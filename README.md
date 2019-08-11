# T4_USB_speedtest
Testing the Teensy 4.0 USB transfer speed

Run  T4_xxx_data via  Arduino/Teensyduino, and note the assigned COM part.  Run the complementary .pde on the PC using processing.org, and set the COM port manually in the code.  ie if using T4_send_data, then use PC_receive_data.  The PC will indicate the transfer rate via console output.

I've reliably measured 3.55 MB/sec transferred from PC to Teensy 4.0 via the code shown here, as well as Paul Stoffregen's original speed test: https://www.pjrc.com/teensy/benchmark_usb_serial_receive.html  The T4 CPU usage was about 15%.

I've measued 7 to 8 MB/sec transferred from Teensy to PC, but it's unstable. The PC code will crash, and cannot seem to keep up with the transfer rate.  Using the "serial monitor" in Arudino will lock up the computer, and eventually throw a java out of memory error.
