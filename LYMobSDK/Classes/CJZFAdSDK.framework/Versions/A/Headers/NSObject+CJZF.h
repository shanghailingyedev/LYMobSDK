//
//  NSObject+CJZF.h
//  CJZFCore
//
//  Created by 早范 on 2025/7/16.
//  
//

#import <Foundation/Foundation.h>

@interface NSObject (CJZF)

- (NSDictionary *)CJZF_toDictionary;

@end

@interface NSArray (CJZF)

- (id)CJZF_objectOrNilAtIndex:(NSUInteger)index;

@end

@interface NSMutableArray (CJZF)

- (void)CJZF_addObjectSafely:(id)anObject;

@end

@interface NSDictionary (CJZF)

- (id)CJZF_objectOrNilForKey:(id)key;

@end


@interface NSMutableDictionary (CJZF)

- (void)CJZF_setValidValue:(id)value forKey:(id<NSCopying>)key;

@end
