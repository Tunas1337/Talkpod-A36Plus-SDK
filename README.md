# Talkpod-A36Plus-SDK
A Software Development Kit (SDK) for the Talkpod A36Plus radio

This project aims to allow users to build firmware images for the Talkpod A36Plus handheld transceiver from scratch. It includes a tool to encode/decode firmware .bin files into .kdhx files, suitable for flashing using the Talkpod bootloader. Of course, you can also use SWD to flash the image directly; however, this includes resetting ReaDout Protection (RDP) to level 0 and wiping the flash including the bootloader, so it is a more involved procedure.

Currently, due to the experimental nature of this tool and the general state of the community, it is not yet publicly available; if you would like to be given some building blocks that you can put together if you know how to, or if you would like to contribute to the project before it goes live, feel free to [contact the author.](mailto:tunas@cryptolab.net)


Special thanks goes out to [OK2MOP](https://github.com/OK2MOP) and [amoxu](https://github.com/amoxu) for their work on the KDHX bootloader tool(s); OK2MOP also supported me heavily on my endeavour of figuring out the intrinsics of ARM MCUs and debugging them, among many other things :^)
