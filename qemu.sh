
#sudo qemu -s -S /dev/sda -kernel arch/i386/boot/bzImage >temp_qemu &
while [ 1 -lt 2 ]
do
pid=`pidof qemu|cut -d ' ' -f1`
sleep 1
if [ "$pid" != "" ]
then
	sleep 5

else
#sudo qemu -smp 1,cores=2 -s -S /dev/sda -kernel arch/x86/boot/bzImage -append "console=ttyS0" -serial mon:stdio
# qemu -smp 1,cores=2 -s -S  -kernel arch/x86/boot/bzImage -append "console=ttyS0" -serial mon:file:out
qemu -kernel arch/x86/boot/bzImage  -append "console=ttyS0" -serial mon:stdio -s -S

	sleep 1
fi
done
