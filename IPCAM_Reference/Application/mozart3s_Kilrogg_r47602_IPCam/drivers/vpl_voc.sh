###############################################
# Generated by Code Generator Version 2.2.0.9 #
###############################################
MODNAME="vpl_voc"

rmmod vpl_voc  > /dev/null 2>&1
rmmod adv7391  > /dev/null 2>&1
rmmod cat6612  > /dev/null 2>&1

rm /dev/$MODNAME > /dev/null 2>&1

insmod adv7391.ko
insmod cat6612.ko
insmod vpl_voc.ko gsdwClkFreq=24 #CLK_SRC#

MAJOR=`cat /proc/devices | grep $MODNAME | sed -e 's/vpl_voc//' | sed -e 's/ //'`

if test -z $MAJOR; then
	echo "The device specified is not found !"
else
	echo "Let's make a node here for $MODNAME with major number $MAJOR"
	mknod /dev/$MODNAME c $MAJOR 0 > /dev/null 2>&1
fi
