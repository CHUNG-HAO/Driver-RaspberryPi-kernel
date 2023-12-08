# Driver-RaspberryPi-kernel
> driver First Experience.

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![GitHub Stars](https://img.shields.io/github/stars/chris911024/Embedded-Linux-kernel?style=flat&label=Stars)](https://github.com/chris911024/Embedded-Linux-kernel/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/chris911024/Embedded-Linux-kernel?style=flat&label=Forks)](https://github.com/chris911024/Embedded-Linux-kernel/network/members)
[![GitHub Issues](https://img.shields.io/github/issues/chris911024/Embedded-Linux-kernel?style=flat&label=Issues)](https://github.com/chris911024/Embedded-Linux-kernel/issues)
## Architecture
> 32 bits
### run
kernel header:
```
sudo apt-get install -y raspberrypi-kernel-headers
```
wpa_cli指令熱身:
> 它可以用來設定連線或者掃描附近的熱點，可以在樹莓派Official OS image中測試它，以下指令可以掃描附近的熱點資訊，包含SSID與信號強度等等

```
wpa_cli -iwlan0 scan_results
```
download:
```
$ sudo insmod mydev.ko
$ dmesg
```

尚有bug, 處理中
