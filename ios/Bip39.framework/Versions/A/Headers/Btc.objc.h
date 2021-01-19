// Objective-C API for talking to github.com/dabankio/wallet-core/core/btc Go package.
//   gobind -lang=objc github.com/dabankio/wallet-core/core/btc
//
// File is generated by gobind. Do not edit.

#ifndef __Btc_H__
#define __Btc_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"

#include "Bip44.objc.h"

@class BtcBTCAddress;
@class BtcBTCAmount;
@class BtcBTCOutputAmount;
@class BtcBTCTransaction;
@class BtcBTCUnspent;
@class BtcBtc;
@class BtcSignRawTransactionResult;

/**
 * BTCAddress .
 */
@interface BtcBTCAddress : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * NewBTCAddressFromString converts a string to a address value.
 */
- (nullable instancetype)initFromString:(NSString* _Nullable)addr chainID:(long)chainID;
@end

/**
 * BTCAmount 对float64 的封装
 */
@interface BtcBTCAmount : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * NewBTCAmount 数量in BTC (not in satoshi)
 */
- (nullable instancetype)init:(double)amount;
@end

/**
 * BTCOutputAmount 交易输出
 */
@interface BtcBTCOutputAmount : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * Add 添加一个交易输出
address 地址
amount 金额
 */
- (void)add:(BtcBTCAddress* _Nullable)address amount:(BtcBTCAmount* _Nullable)amount;
@end

/**
 * BTCTransaction represents a single bitcoin transaction.
 */
@interface BtcBTCTransaction : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * NewBTCTransaction creates a new bitcoin transaction with the given properties.
unSpent : listUnspent
amounts: toAddress + amount
change: 找零地址
feeRate: 单位手续费/byte
testNet: 测试网络传true
 */
- (nullable instancetype)init:(BtcBTCUnspent* _Nullable)unSpent amounts:(BtcBTCOutputAmount* _Nullable)amounts change:(BtcBTCAddress* _Nullable)change feeRate:(int64_t)feeRate chainID:(long)chainID;
/**
 * Encode encode to raw transaction
 */
- (NSString* _Nonnull)encode:(NSError* _Nullable* _Nullable)error;
/**
 * EncodeToSignCmd 结果可以用于签名接口
 */
- (NSString* _Nonnull)encodeToSignCmd:(NSError* _Nullable* _Nullable)error;
/**
 * EncodeToSignCmdForNextSigner 构造给下个签名者签名的命令，
signedRawTX: 当前签名者已签名好的交易数据
 */
- (NSString* _Nonnull)encodeToSignCmdForNextSigner:(NSString* _Nullable)signedRawTX error:(NSError* _Nullable* _Nullable)error;
/**
 * GetFee 获取目前的费率(in BTC, not satoshi)
Returns the miner's fee for the current transaction
 */
- (BOOL)getFee:(double* _Nullable)ret0_ error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * BTCUnspent represents a single bitcoin transaction.
 */
@interface BtcBTCUnspent : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * Add add one utxo
 */
- (void)add:(NSString* _Nullable)txId vOut:(int64_t)vOut amount:(double)amount scriptPubKey:(NSString* _Nullable)scriptPubKey redeemScript:(NSString* _Nullable)redeemScript;
@end

/**
 * Btc (全部大写在导出到java那边有点问题)
 */
@interface BtcBtc : NSObject <goSeqRefInterface, Bip44Deriver> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
// skipped field Btc.BTC with unsupported type: github.com/dabankio/wallet-core/core/btc/internal.BTC

- (NSString* _Nonnull)decodeTx:(NSString* _Nullable)msgTx error:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)deriveAddress:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)derivePrivateKey:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)derivePublicKey:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)rawKey:(NSError* _Nullable* _Nullable)error;
- (NSString* _Nonnull)sign:(NSString* _Nullable)rawTx privateKeyWif:(NSString* _Nullable)privateKeyWif error:(NSError* _Nullable* _Nullable)error;
- (BOOL)verifySignature:(NSString* _Nullable)pubKey rawTx:(NSString* _Nullable)rawTx signedRawTx:(NSString* _Nullable)signedRawTx error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * SignRawTransactionResult 签名结果
 */
@interface BtcSignRawTransactionResult : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull hex;
@property (nonatomic) BOOL changed;
@property (nonatomic) BOOL complete;
@property (nonatomic) NSString* _Nonnull errors;
@end

/**
 * ChainMainNet 链：MainNet
 */
FOUNDATION_EXPORT const int64_t BtcChainMainNet;
/**
 * ChainRegtest 链：Regression
 */
FOUNDATION_EXPORT const int64_t BtcChainRegtest;
/**
 * ChainTestNet3 链：TestNet3
 */
FOUNDATION_EXPORT const int64_t BtcChainTestNet3;
/**
 * FlagUseSegWitFormat BTC使用隔离见证地址
 */
FOUNDATION_EXPORT NSString* _Nonnull const BtcFlagUseSegWitFormat;

@interface Btc : NSObject
// skipped variable New with unsupported type: func(bip44Path string, isSegWit bool, seed []byte, chainID int) (c *github.com/dabankio/wallet-core/core/btc/internal.BTC, err error)

@end

/**
 * Hello 返回简单的hello 字符串，可用于验证api调用
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcHello(void);

// skipped function InternalNewBTCTransaction with unsupported parameter or return types


/**
 * NewBTCAddressFromString converts a string to a address value.
 */
FOUNDATION_EXPORT BtcBTCAddress* _Nullable BtcNewBTCAddressFromString(NSString* _Nullable addr, long chainID, NSError* _Nullable* _Nullable error);

/**
 * NewBTCAmount 数量in BTC (not in satoshi)
 */
FOUNDATION_EXPORT BtcBTCAmount* _Nullable BtcNewBTCAmount(double amount, NSError* _Nullable* _Nullable error);

/**
 * NewBTCTransaction creates a new bitcoin transaction with the given properties.
unSpent : listUnspent
amounts: toAddress + amount
change: 找零地址
feeRate: 单位手续费/byte
testNet: 测试网络传true
 */
FOUNDATION_EXPORT BtcBTCTransaction* _Nullable BtcNewBTCTransaction(BtcBTCUnspent* _Nullable unSpent, BtcBTCOutputAmount* _Nullable amounts, BtcBTCAddress* _Nullable change, int64_t feeRate, long chainID, NSError* _Nullable* _Nullable error);

/**
 * NewBip44Deriver btc bip44 实现
 */
FOUNDATION_EXPORT id<Bip44Deriver> _Nullable BtcNewBip44Deriver(NSString* _Nullable bip44Path, BOOL isSegWit, NSData* _Nullable seed, long chainID, NSError* _Nullable* _Nullable error);

// skipped function NewCoin with unsupported parameter or return types


// skipped function NewFromMetadata with unsupported parameter or return types


/**
 * NewMultiSigAddress 工具函数，生成BTC多签地址
Params:
 chainID: 0主链,1测试链,2Regression链
 cmd.NRequired 需要签名的人数
 cmd.Keys hex编码的公钥
限制：len(cmd.Keys) >= cmd.NRequired
Return:
 多签地址,redeemScript
 */
FOUNDATION_EXPORT NSString* _Nonnull BtcNewMultiSigAddress(long mRequired, long chainID, NSString* _Nullable keys, NSError* _Nullable* _Nullable error);

/**
 * SignRawTransactionWithKey Refer to https://bitcoin.org/en/developer-reference#signrawtransactionwithkey
Diff from rpc:
    sighashtype is set to "ALL"
    single private key
 */
FOUNDATION_EXPORT BtcSignRawTransactionResult* _Nullable BtcSignRawTransactionWithKey(NSString* _Nullable hexstring, NSString* _Nullable privateKeyWif, BtcBTCUnspent* _Nullable unspents, long chainFlag, NSError* _Nullable* _Nullable error);

/**
 * SignTransaction signs tx with wif privateKey
tx: transaction
privateKeyWif: private key in wallet import format(wif)
chainFlag: chain id
return: {
    changed: (bool, 签名后的内容是否发生变化，),
	   complete: (bool， 含不同地址的输入或多重签名情况下即使提供正确的私钥也可能存在签名未完成的情况),
    hex: (string, 前后的rawTransactionHex)
    errors: (string 可作为调试参考的错误信息)
}
 */
FOUNDATION_EXPORT BtcSignRawTransactionResult* _Nullable BtcSignTransaction(BtcBTCTransaction* _Nullable tx, NSString* _Nullable privateKeyWif, long chainFlag, NSError* _Nullable* _Nullable error);

#endif
