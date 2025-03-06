#!/bin/bash

#-----------------------------------------------------------------------
# Setup Source Code
#-----------------------------------------------------------------------
git clone https://github.com/openwrt/openwrt openwrt
cd openwrt

#git remote add origin https://github.com/openwrt/openwrt
#git branch --set-upstream-to=origin/master master

git branch -vv
git remote -vv

git remote add upstream https://git.openwrt.org/openwrt/openwrt.git
git remote add dev git@github.com:faijurrahman/openwrt.git

git branch -vv
git remote -vv


#-----------------------------------------------------------------------
# Build OpenWrt
#-----------------------------------------------------------------------
