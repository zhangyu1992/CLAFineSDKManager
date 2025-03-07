//
//  GSDocEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GSDocShareType)
{
    GSDocShareType_Doc,
    GSDocShareType_Wb,
};

struct UploadBack {
    GSDoc *doc;
    NSInteger upSize;
};
typedef struct CG_BOXABLE UploadBack uploadBack;

typedef NS_ENUM(NSInteger, GSDocMode)
{
    GSDocMode_pic,        //图片
    GSDocMode_html,       //动画
    GSDocMode_html_first, //动画优先
};

/**
 *文档相关回调
 */
@protocol GSDocEvent <NSObject>
/**
 *当前共享类型
 *type: 0 文档 1白板
*/
- (void)onDocShareType:(GSDocShareType)type;

/**
 *文档列表
*/
- (void)onAddDocList:(NSArray<GSDoc *>*)docList;

/**
 *白板信息
*/
- (void)onAddWhiteBoardInfo:(GSDoc *)doc;

/**
 *共享文档的信息
 */
-(void)ondocShareInfoChange:(GSDoc *)doc;

/**
 *共享文档的页码
 */
-(void)ondocSharePageInfo:(NSString *)docId page:(GSPage *)page;


/**
 *添加白板方法回调
 */
-(void)onWhiteBoardAdded:(GSWhiteBoardPage *)wbPage;

/**
 *文档状态
 *resourceId: 文档资源id
 *publish：YES发布；  NO取消发布
 *bindType：YES绑定；  NO取消绑定
 *isDelete：YES 删除
 */
- (void)onDocStatusChange:(NSString *)resourceId publish:(BOOL)publish bindType:(BOOL)bindType isDelete:(BOOL)isDelete;

/**
 *文档添加进度
 *progress: 文档大小
 *doc：文档信息
*/
- (void)onDocAddStatus:(GSDoc *)doc progress:(NSInteger)progress;


@end

NS_ASSUME_NONNULL_END
