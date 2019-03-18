## Introduction 
xzf is a simple PoC demonstrating how EXIF data can be used for command and control. xzf GETs an image from a predetermined URL, then reads the software tag for an authentication string. If the string matches, xzf will execute anything contained within the ImageDescription tag. 

## Usage 
1. Choose your auth string and XOR key, then use xor.py to XOR out the string
2. Choose an image and use [gexif](https://github.com/libexif/gexif) to add your commands to execute in ImageDescription and your auth string to the Software tag. 
4. XOR out the desired filename 
5. Upload the image (not imgur) and add all values to consts.h 
6. Deploy 

### References
- https://www.media.mit.edu/pia/Research/deepview/exif.html
- https://blog.sucuri.net/2013/07/malware-hidden-inside-jpg-exif-headers.html
