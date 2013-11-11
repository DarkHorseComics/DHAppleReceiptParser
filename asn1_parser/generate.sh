# this is the command used to generate the code in this directory
asn1c -fincludes-quoted -fnative-types Receipt.asn1
rm Makefile.am.sample converter-sample.c

