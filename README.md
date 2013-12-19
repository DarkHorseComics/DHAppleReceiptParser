A library to parse the apple receipt file in iOS 7 as defined in the [apple developer documentation]
(https://developer.apple.com/library/ios/releasenotes/General/ValidateAppStoreReceipt/Chapters/ValidateLocally.html#//apple_ref/doc/uid/TP40010573-CH1-SW3).  

This library does *not* handle validation -- by Apple's design, it
is necessary to provide your own validation code for security reasons.  

This library *does* make it easier to fetch in-app purchase data stored
on the device, which could be used for server side receipt validation.  

To get the parsed system receipt:

```
#import "DHAppStoreReceipt.h"

// This function could be used to get the recipt payload for server side validation
//  of in app purchases
- (NSData *)receiptDataForProductIdentifier:(NSString *)productIdentifier {
    DHAppStoreReceipt *receipt = [DHAppStoreReceipt mainBundleReceipt];
    DHInAppReceipt *inAppReceipt = [receipt receiptForProductId:productIdentifier];
    return inAppReceipt.receiptData;
}
```

OpenSSL is included as built by https://github.com/st3fan/ios-openssl
