//
//  CCAdapterBase.h
//  test_adapter
//
//  Created by jinxiangkun on 17/4/5.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCModelBase.h"
#import "CCModelStruct.h"
#import "CCModelMessage.h"
#import "CCModelMethod.h"
#import "CCModelGroup.h"

#import "CCModelTransform.h"
#import "CCModelKeyUtility.h"
#import "CCServiceManager.h"
#import "CCServiceProtocol.h"
#import "CCModelDataUtility.h"

enum MyNodeType
{
    MyBaseTypeUnknow = CCBaseTypeUnknow,
    MyBaseTypeUser = CCBaseTypeUser, //用户类型
    MyBaseTypeDepart = CCBaseTypeDepart, //部门类型
    MyBaseTypeCustomer = CCBaseTypeCustomer, //客户类型
    MyBaseTypeDepartUser = CCBaseTypeDepartUser, //部门用户类型
};
typedef enum MyNodeType MyNodeType;

// 部门节点抽像
@interface CCNodeBase : NSObject

@property (assign) MyNodeType type; //节点类型
@property (strong) NSString * id_; //通用id，uid or did
@property (strong) NSString * cid; //客户id
@property (strong) NSString * identifyID; //索引ID
@property (strong) NSString * pdid; //部门的上级id
@property (strong) NSString * name; //部门名字，必填
@property (strong) NSString * pinyin; //拼音
@property (strong) NSString * pyhead; //拼音头
@property (assign) NSInteger  sort; //同级部门排序值
@property (strong) NSString * path; //部门路径，如：/1/2/3/
@property (assign) NSInteger  level; //层级，依次类推
@property (assign) NSInteger  usernum; //部门用户数量
@property (strong) NSMutableArray * parents; //部门节点上级
@property (strong) NSMutableDictionary * parentsMap; //部门节点上级
@property (strong) NSMutableArray * childrens; //部门节点子级
@property (strong) NSMutableDictionary * childrensMap; //部门节点子级

- (NSInteger)getSort;
// 获得第一项上级节点
- (CCNodeBase *)getParentNode;
// 获得路径的数组信息
- (NSMutableArray *)getAllPathID;

// 将其他节点信息拷贝至当前节点
- (void)updateNodeInfo:(CCNodeBase *)other;
// 添加上级信息节点，如果存在则更新
- (void)addParentNode:(CCNodeBase *)node key:(NSString *)nodeKey;
// 添加子一级信息节点，如果存在则更新
- (void)addChildrenNode:(CCNodeBase *)node key:(NSString *)nodeKey;

@end

@interface CCNodeUtility : NSObject

// 类型转换帮助类
+ (CCNodeBase *)nodeWithRosterBase:(CCNameSpace(CCRosterBase) *)info;
// 类型转换帮助类
+ (CCNodeBase *)nodeWithRosterUser:(CCNameSpace(CCRosterUser) *)info;
+ (CCNodeBase *)nodeWithResultUser:(CCNameSpace(CCResultUser) *)info;
+ (CCNodeBase *)nodeWithRosterCustomer:(CCNameSpace(CCRosterCustomer) *)info;
+ (CCNodeBase *)nodeWithRosterDepartment:(CCNameSpace(CCRosterDepartment) *)info;
+ (CCNodeBase *)nodeWithResultDepartment:(CCNameSpace(CCResultDepartment) *)info;
+ (CCNodeBase *)nodeWithRosterDepartmentUser:(CCNameSpace(CCRosterDepartmentUser) *)info;

@end
