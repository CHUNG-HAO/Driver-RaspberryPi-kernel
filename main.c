#include <linux/module.h>
#include <linux/device.h>
#include <linux/err.h>



// 將使用者從 user_space 傳遞給內核的數值字串轉換為整數，並將其儲存在全域變數中，同時在kernel module中列印該數值。
/*
1. attr_store  =  使用者空間的字串轉換為整數值，並將該值儲存在全域變數  value
2. dev 是指向樹梅派的指標
3. attr  是指向裝置屬性的指標
4. buf  是包含使用者輸入的字串的緩衝區
5. count 是字串的長度
*/
int value = 0;

static ssize_t attr_store(struct device* dev, struct device_attribute* attr, const char* buf, size_t count)

/*
simple_strtoul 函數將 buf 中的字串轉換為無符號長整數，並將其賦值給  value  變數。
使用 printk 函數將 value 的值輸出到kernel module中。 
*/

{
    value = simple_strtoul(buf, NULL, 10);
    printk("value:%d\n", value);
    return count;
                        }

static ssize_t attr_show(struct device *dev, struct device_attribute *attr, char *buf)
{
        int val=0;
        val=sprintf(buf, "%d\n",value);
        printk("%d\n", val);
        return val;
}

static struct class *mydev_class;
static struct device *dev;

static DEVICE_ATTR(data, 0644, attr_show, attr_store);

static int __init init_mydev(void)
{
	int ret = 0;
	printk("Init my dev\n");
	mydev_class = class_create(THIS_MODULE, "mydev_class");
	if(IS_ERR(mydev_class)) {
		ret = PTR_ERR(mydev_class);
		printk(KERN_ALERT "Failed to create class.\n");
		return ret;
	}

	dev = device_create(mydev_class, NULL, MKDEV(100,0), NULL, "dev");
	if(IS_ERR(dev)) {
		ret = PTR_ERR(dev);
		printk(KERN_ALERT "Failed to create device.\n");
		return ret;
	}

	ret = device_create_file(dev, &dev_attr_data);
	if(ret < 0) {
		printk(KERN_ALERT "Failed to create attribute file.\n");
		return ret;
	}
	return ret;
}

static void __exit cleanup_mydev(void)
{
	printk("Cleanup my dev\n");
	device_remove_file(dev, &dev_attr_data);
	device_destroy(mydev_class, MKDEV(100, 0));
	class_destroy(mydev_class);
}

module_init(init_mydev);
module_exit(cleanup_mydev);

MODULE_LICENSE("GPL");
