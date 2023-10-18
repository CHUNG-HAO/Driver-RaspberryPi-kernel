# Embedded-Linux-kernel

## Architecture
<img width="645" alt="image" src="https://github.com/chris911024/Embedded-Linux/assets/67829896/87a9424e-5bd5-4f12-b31b-44c20de5438d">

### run
kernel header
```
sudo apt-get install -y raspberrypi-kernel-headers
```
wpa_cli指令熱身:
> 它可以用來設定連線或者掃描附近的熱點，可以在樹莓派Official OS image中測試它，以下指令可以掃描附近的熱點資訊，包含SSID與信號強度等等

```
wpa_cli -iwlan0 scan_results
```
