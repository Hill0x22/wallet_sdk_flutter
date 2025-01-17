// Objective-C API for talking to github.com/dabankio/wallet-core/bip39 Go package.
//   gobind -lang=objc github.com/dabankio/wallet-core/bip39
//
// File is generated by gobind. Do not edit.

#ifndef __Bip39_H__
#define __Bip39_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


/**
 * LangChineseSimplified 简体中文
 */
FOUNDATION_EXPORT const int64_t Bip39LangChineseSimplified;
/**
 * LangChineseTraditional 繁体中文
 */
FOUNDATION_EXPORT const int64_t Bip39LangChineseTraditional;
/**
 * LangEnglish 英语
 */
FOUNDATION_EXPORT const int64_t Bip39LangEnglish;
/**
 * LangFrench 法语
 */
FOUNDATION_EXPORT const int64_t Bip39LangFrench;
/**
 * LangItalian 意大利语
 */
FOUNDATION_EXPORT const int64_t Bip39LangItalian;
/**
 * LangJapanese 日文
 */
FOUNDATION_EXPORT const int64_t Bip39LangJapanese;
/**
 * LangKorean 韩文
 */
FOUNDATION_EXPORT const int64_t Bip39LangKorean;
/**
 * LangSpanish 西班牙语
 */
FOUNDATION_EXPORT const int64_t Bip39LangSpanish;

@interface Bip39 : NSObject
/**
 * ErrChecksumIncorrect is returned when entropy has the incorrect checksum.
 */
+ (NSError* _Nullable) errChecksumIncorrect;
+ (void) setErrChecksumIncorrect:(NSError* _Nullable)v;

/**
 * ErrEntropyLengthInvalid is returned when trying to use an entropy set with
an invalid size.
 */
+ (NSError* _Nullable) errEntropyLengthInvalid;
+ (void) setErrEntropyLengthInvalid:(NSError* _Nullable)v;

/**
 * ErrInvalidMnemonic is returned when trying to use a malformed mnemonic.
 */
+ (NSError* _Nullable) errInvalidMnemonic;
+ (void) setErrInvalidMnemonic:(NSError* _Nullable)v;

/**
 * ErrValidatedSeedLengthMismatch is returned when a validated seed is not the
same size as the given seed. This should never happen is present only as a
sanity assertion.
 */
+ (NSError* _Nullable) errValidatedSeedLengthMismatch;
+ (void) setErrValidatedSeedLengthMismatch:(NSError* _Nullable)v;

@end

/**
 * EntropyFromMnemonic takes a mnemonic generated by this library,
and returns the input entropy used to generate the given mnemonic.
An error is returned if the given mnemonic is invalid.
 */
FOUNDATION_EXPORT NSData* _Nullable Bip39EntropyFromMnemonic(NSString* _Nullable mnemonic, NSError* _Nullable* _Nullable error);

// skipped function GetWordList with unsupported parameter or return types


/**
 * GetWordListString 当前词汇表（以,分隔）
 */
FOUNDATION_EXPORT NSString* _Nonnull Bip39GetWordListString(void);

/**
 * Hello 返回简单的hello 字符串，可用于验证api调用
 */
FOUNDATION_EXPORT NSString* _Nonnull Bip39Hello(void);

/**
 * IsMnemonicValid attempts to verify that the provided mnemonic is valid.
Validity is determined by both the number of words being appropriate,
and that all the words in the mnemonic are present in the word list.
 */
FOUNDATION_EXPORT BOOL Bip39IsMnemonicValid(NSString* _Nullable mnemonic);

// skipped function MnemonicToByteArray with unsupported parameter or return types


/**
 * NewEntropy will create random entropy bytes
so long as the requested size bitSize is an appropriate size.

bitSize has to be a multiple 32 and be within the inclusive range of {128, 256}
 */
FOUNDATION_EXPORT NSData* _Nullable Bip39NewEntropy(long bitSize, NSError* _Nullable* _Nullable error);

/**
 * NewMnemonic will return a string consisting of the mnemonic words for
the given entropy.
Words are splitted by one space, eg: 丝 吨 第 序 东 收 供 已 涌 爹 子 览 , bag dentist hero goddess art top picnic load certain neither thumb lift
If the provide entropy is invalid, an error will be returned.
 */
FOUNDATION_EXPORT NSString* _Nonnull Bip39NewMnemonic(NSData* _Nullable entropy, NSError* _Nullable* _Nullable error);

/**
 * NewSeed creates a hashed seed output given a provided string and password.
No checking is performed to validate that the string provided is a valid mnemonic.
 */
FOUNDATION_EXPORT NSData* _Nullable Bip39NewSeed(NSString* _Nullable mnemonic, NSString* _Nullable password);

/**
 * NewSeedWithErrorChecking creates a hashed seed output given the mnemonic string and a password.
An error is returned if the mnemonic is not convertible to a byte array.
 */
FOUNDATION_EXPORT NSData* _Nullable Bip39NewSeedWithErrorChecking(NSString* _Nullable mnemonic, NSString* _Nullable password, NSError* _Nullable* _Nullable error);

// skipped function SetWordList with unsupported parameter or return types


/**
 * SetWordListLang 设置词汇表语言(默认英语)
 */
FOUNDATION_EXPORT BOOL Bip39SetWordListLang(long lang, NSError* _Nullable* _Nullable error);

#endif
