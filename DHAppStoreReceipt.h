//
// Created by Chase Caster on 11/8/13.
// Copyright 2012 Dark Horse Comics
//


#import <Foundation/Foundation.h>

@class DHInAppReceipt;

typedef enum {
    DH_ATTRIBUTE_TYPE_BUNDLE_ID = 1,
    DH_ATTRIBUTE_TYPE_APPLICATION_VERSION = 3,
    DH_ATTRIBUTE_TYPE_OPAQUE_VALUE = 4,
    DH_ATTRIBUTE_TYPE_SHA_HASH = 5,
    DH_ATTRIBUTE_TYPE_IN_APP_RECEIPT = 17,
    DH_ATTRIBUTE_TYPE_ORIGINAL_APPLICATION_VERSION = 19,
    DH_ATTRIBUTE_IN_APP_TYPE_QUANTITY = 1701,
    DH_ATTRIBUTE_IN_APP_TYPE_PRODUCT_ID = 1702,
    DH_ATTRIBUTE_IN_APP_TYPE_TRANSACTION_ID = 1703,
    DH_ATTRIBUTE_IN_APP_TYPE_ORIGINAL_TRANSACTION_ID = 1705,
    DH_ATTRIBUTE_IN_APP_TYPE_PURCHASE_DATE = 1704,
    DH_ATTRIBUTE_IN_APP_TYPE_ORIGINAL_PURCHASE_DATE = 1706,
    DH_ATTRIBUTE_IN_APP_TYPE_SUBSCRIPTION_EXPIRATION_DATE = 1708,
    DH_ATTRIBUTE_IN_APP_TYPE_CANCELLATION_DATE = 1712,
    DH_ATTRIBUTE_IN_APP_TYPE_WEB_ORDER_LINE_ITEM_ID = 1711
} DHAttributeType;

@interface DHASN1Attribute : NSObject

- (id)initWithType:(DHAttributeType)type version:(NSInteger)version value:(id)value;

@property DHAttributeType type;
@property NSInteger version;
@property(readonly) NSData *dataValue;
@property(readonly) NSString *stringValue;
@property(readonly) NSDate *dateValue;
@property(readonly) NSInteger integerValue;

@end

@interface DHASN1Parser : NSObject

- (NSArray *)attributesForData:(NSData *)data;

@end

@interface DHAppStoreReceipt : DHASN1Parser

+ (DHAppStoreReceipt *)mainBundleReceipt;
- (id)initWithURL:(NSURL *)receiptURL;
- (DHInAppReceipt *)receiptForProductId:(NSString *)productId;

@property(readonly) NSString *bundleId;
@property(readonly) NSString *applicationVersion;
@property(readonly) NSData *opaqueValue;
@property(readonly) NSData *SHA1Hash;
@property(readonly) NSArray *inAppReceipts;
@property(readonly) NSString *originalApplicationVersion;

@end

@interface DHInAppReceipt : DHASN1Parser

- (id)initWithData:(NSData *)data;

@property(readonly) NSInteger quantity;
@property(readonly) NSString *productId;
@property(readonly) NSString *transactionId;
@property(readonly) NSString *originalTransactionId;
@property(readonly) NSDate *purchaseDate;
@property(readonly) NSDate *originalPurchaseDate;
@property(readonly) NSDate *subscriptionExpirationDate;
@property(readonly) NSDate *cancellationDate;
@property(readonly) NSInteger webOrderLineItemId;

@property(readonly) NSData *receiptData;

@end
