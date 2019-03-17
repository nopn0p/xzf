## Introduction 
xzf is a simple PoC demonstrating how EXIF data can be used for command and control. xzf GETs an image from a predetermined URL, then reads the software tag for an authentication string. If the string matches, xzf will execute anything contained within the ImageDescription tag. 

### References
https://www.media.mit.edu/pia/Research/deepview/exif.html
https://blog.sucuri.net/2013/07/malware-hidden-inside-jpg-exif-headers.html
