//
//  GlobalTool.h
//

#ifndef PABank2_Global_h
#define PABank2_Global_h

/*==================开 关 登 记======================*/

//是否启用TCP TLV报文格式循环移位
#ifndef __CYCLE_SHIFT__
#define __CYCLE_SHIFT__
#endif


/*=================离线消息获取==============*/
#define kTheOfflineMesageCount      @"50"
//#define kOfflineMessageID           @"messageidofoffline"

/*========================================屏幕适配============================================*/
#define kIOSVersions [[[UIDevice currentDevice] systemVersion] floatValue] //获得iOS版本
#define kUIWindow    [[[UIApplication sharedApplication] delegate] window] //获得window
#define kUnderStatusBarStartY (kIOSVersions>=7.0 ? 20 : 0)                 //7.0以上stautsbar不占位置，内容视图的起始位置要往下20

#define kScreenSize           [[UIScreen mainScreen] bounds].size                 //(e.g. 320,480)
#define kScreenWidth          [[UIScreen mainScreen] bounds].size.width           //(e.g. 320)
#define kScreenHeight  (kIOSVersions>=7.0 ? [[UIScreen mainScreen] bounds].size.height + 64 : [[UIScreen mainScreen] bounds].size.height)
#define kIOS7OffHeight (kIOSVersions>=7.0 ? 64 : 0)
#define kHeightFromSatus (kIOSVersions>=7.0 ? 24 : 0)


#define kApplicationSize      [[UIScreen mainScreen] applicationFrame].size       //(e.g. 320,460)
#define kApplicationWidth     [[UIScreen mainScreen] applicationFrame].size.width //(e.g. 320)
#define kApplicationHeight    [[UIScreen mainScreen] applicationFrame].size.height//不包含状态bar的高度(e.g. 460)

#define kStatusBarHeight         20
#define kNavigationBarHeight     44
#define kNavigationheightForIOS7 64
#define kContentHeight           (kApplicationHeight - kNavigationBarHeight)
#define kTabBarHeight            49
#define kTableRowTitleSize       14
#define maxPopLength             215
#define kSeekTabBarHeight (kIOSVersions>=7.0 ? 0 : 49)  //活动主页适配用
/*======================================xmpp请求错误提示码==========================================*/
#define noPassAuth                          @"401"                           //请求未通过身份认证
#define loginOtherDevice                    @"409"                           //用户在其它设备登录
#define noSetPassword                       @"664"                           //未设置密码
#define NoRegister                          @"0"                           //此手机号未注册
#define AlreadyRegister                     @"1"                           //此手机号已经被注册
#define phoneNumExist                       @"658"                           //手机号码已存在
#define phoneNumNotRegister                 @"651"                           //手机号码尚未注册天下通
#define phoneCodeNotTure                    @"659"                           //手机验证码不正确
#define phoneCodePastDue                    @"667"                           //手机验证码已过期
#define nickNameNotRight                    @"601"                           //用户昵称含有被限制的字符
#define frequentOperation                   @"800"                           //由于输入错误密码次数过多
#define PAAccountLocked                     @"802"                           //账号已锁定
#define TokenInvalidation                   @"803"                           //token验证10次错误
#define TokenInvalidationAccountLocked      @"804"                           //token验证10次错误,账号被锁定
#define verificationCodeError               @"888"                           //手机otp验证码错误
#define verificationCodeErrorAccountLocked  @"889"                           //手机otp验证码错误，账号被锁定
#define PATermsConditionsUrl @"http://txt.pingan.com.cn/static/sem/service/services.html"//服务条款协议地址
#define HttpLowNetworkSpeed    1.0               //http网络低速阀值
#define TcpLowNetworkSpeed     0.05              //tcp网络低速阀值
#define PingLowNetworkSpeed    2.5               //心跳包网络低速阀值

#define PACHATLocalizedString(nonstring) NSLocalizedString(nonstring,nonstring)   //本地化字符串

/*======================================第三方函数==========================================*/
//比较字符串是否相等（忽略大小写），相等的话返回YES，否则返回NO。
#define CompareStringCaseInsenstive(thing1, thing2) [thing1 compare:thing2 options:NSCaseInsensitiveSearch|NSNumericSearch] == NSOrderedSame


/*======================================字体/颜色==========================================*/
#define kBlackFontAndAlpha(fontAlpha)   [UIColor colorWithRed:0.0f/255.0f green:0.0f/255.0f blue:0.0f/255.0f alpha:fontAlpha]                                                        //黑色字体,透明度
#define kStatementFontSize    [UIFont systemFontOfSize:12]            //陈述字体大小
#define kNavigationItemFontSize    [UIFont systemFontOfSize:15]       //NavigationItem字体大小
#define kTextFontSize         [UIFont systemFontOfSize:16]            //正文字体大小
#define kButtonFontSize       [UIFont systemFontOfSize:19]            //按钮字体大小
#define kTitleFontSize        [UIFont systemFontOfSize:20]            //NavigationBar标题字体
#define kBackgroudColor       [UIColor colorWithRed:239.0f/255.0f green:239.0f/255.0f blue:245.0f/255.0f alpha:1.0f]
#define kSwitchButtonTintColor   [UIColor orangeColor]
#define kPhoneNumFontSize     [UIFont systemFontOfSize:19]             //上次登录帐号字体大小
#define kTiptextFontSize      [UIFont systemFontOfSize:14]
#define kBackGroundImage      [UIImage imageNamed:@"shurukuang.png"]  //输入框背景图片


#pragma mark --- 超时请求
#define kNotifyOfOutTimer       @"requestoutoftime"                     //请求超时
#define kCountOfOutTime         30.0
#define kTxtVersion            [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

#pragma mark ---------------- 通知------------

#define kNotifyLoginSuccess                     @"kNotifyLoginSuccess"                      //登录成功
#define kNotifyAddEnrollAlertView               @"AddenrollAlertView"                       //注册后添加活动报名页
#define KNotifyTipVerificationView              @"TipVerificationView"                      //注册成功后提示绑定信用卡
#define kNotifyDimensionRefreshed               @"kNotifyDimensionRefreshed"                //任意门会话刷新
#define kNotifyConversationRefreshed            @"kNotifyConversationRefreshed"             //消息会话刷新
#define kNotifyConversationBadgeNumberRefreshed @"kNotifyConversationBadgeNumberRefreshed"  //未读消息刷新
#define kNotifyMessageReceived                  @"kNotifyMessageReceived"                   //收到消息通知

#define kNotifyFriendDetailRefreshed            @"kNotifyFriendDetailRefreshed"            //修改好友详情
#define kNotifyUpdateFriend                     @"kNotifyUpdateFriend"                     //更新好友
#define kNotifySearchSuccess                    @"searchSuccess"                           //成功搜索到好友

#define kNotifyScanSearchSuccess     @"scanSearchSuccess"                       //二维码搜索好友详细信息成功
#define kNotifyScanSearchFail        @"ScanSearchFail"                          //二维码搜索好友详细信息失败
#define kNotifyScanJoinGroup         @"ScanJoinGroup"                           //二维码加入群获取群成员成功
#define kNotifyBlackSearchSuccess    @"kNotifyBlackSearchSuccess"               //黑名单查询详细信息成功
#define kNotifyBlackSearchFail       @"kNotifyBlackSearchFail"                  //黑名单查询详细信息失败
#define kNotifyRemoveBackListSuccess @"RemoveBackListSuccess"                   //移出黑名单成功
#define kNotifyRemoveBackListFail    @"RemoveBackListFail"                      //移出黑名单失败
#define kNotifyAddToBackListSuccess  @"kNotifyAddToBackListSuccess"             //加入黑名单成功
#define kNotifyAddToBackListSuccessUserInfoFriendModel @"kNotifyAddToBackListSuccessUserInfoFriendModel" //加入黑名单成功后发出通知中的friendModel在userInfo中的key
#define kNotifyAddToBackListFail     @"kNotifyAddToBackListFail"                //加入黑名单失败
#define kNotifyAddFriendSuccess      @"kNotifyAddFriendSuccess"                 //成功添加好友
#define kNotifyAddFriendFail         @"kNotifyAddFriendFail"                    //对方添加好友
#define kNotifySearchUserFail        @"searchUserFail"                          //搜索好友失败
#define kAcceptFriendSuccess         @"kAcceptFriendSuccess"                    //"接受好友" 等待验证页面


#define kNotifySearchUserFromSearchFail_Error    @"kNotifySearchUserFromSearchFail_error"   //从添加好友搜索失败
#define kNotifySearchUserFromSearchFail    @"kNotifySearchUserFromSearchFail"   //从添加好友搜索未找到
#define kNotifySearchUserFromSearchSuccess @"kNotifySearchUserFromSearchSuccess"//从添加好友搜索成功
#define kNotifySearchPublicSuccess         @"searchPublicSuccess"               //搜索公众号成功
#define kNotifyChatSettingRefreshed        @"kNotifyChatSettingRefreshed"       //聊天设置更新
#define kNotifyChatSettingBackground       @"kNotifyChatSettingBackground"      //设置聊天背景
#define kNotifykStrangerSearchSuccess      @"kNotifykStrangerSearchSuccess"     //搜索手机通讯录好友成功
#define kNotifyModifyRemarkNameSuccess     @"kNotifyModifyRemarkNameSuccess"    //修改备注名成功
#define kNotifyMessageInsert               @"kNotifyMessageInsert"              //插入消息
#define kNotifyMessageStateChanged         @"kNotifyMessageStateChanged"        //消息发送状态更新
#define kNotifyUploadProgressChanged       @"kNotifyUploadProgressChanged"      //上传进度
#define kNotifyMessageDeleted              @"kNotifyMessageDeleted"             //消息删除
#define kNotifyNewFriendSearchSuccess      @"kNotifyNewFriendSearchSuccess"     //新朋友查询
//#define kNewFriendSearchId                 @"kNewFriendSearchId"                //新朋友搜索id
#define kAddUserIQId                       @"kAddUserIQId"                      //添加好友第一条消息iq id
#define kAddUserPresenceId                 @"kAddUserPresenceId"                //添加好友第一条presence id
#define kAddUserPresenceSubscribe          @"kAddUserPresenceSubscribe"         //添加好友第一条presence id
#define kAddRemoveIQId                     @"kAddRemoveIQId"                    //添加好友第一条消息iq id
#define kNotifyModifyRemarkNameSuccessOfGroup   @"changeroommembernicknamesuccess"
#define kNotifyAddGroupByOtherPeople       @"kNotifyAddGroupByOtherPeople"      //被加入群的通知，便于刷新右侧按钮

//新朋友
#define kNotifyNewFriendRefreshed               @"kNotifyNewFriendRefreshed"              //新朋友通知
#define kNotifyNewFriendBadgeNumberRefreshed    @"kNotifyNewFriendBadgeNumberRefreshed"   //新朋友badge通知
#define kNewfriendmessage                       @"newfriendmessage"
#define kNotifyNewFriendSendMessageSuccess      @"NotifyNewFriendSendMessageSuccess"      // 发送成功
#define kNotifyNewFriendSendMessageFail         @"NotifyNewFriendSendMessageFail"         // 发送失败
#define kNotifyNewFriendReceiveMessageSuccess   @"NotifyNewFriendReceiveMessageSuccess"   // 接收消息
#define kNotifyDeleteNewFriendSuccess           @"deleteNewFriendSuccess"                 //删除新朋友成功
#define kNotifyFetchFriendDetailsSuccess        @"NotifyFetchFriendDetailsSuccess"        // 查看个人详情成功

//添加好友确定button notification
#define kAddFriendConfirmNotification           @"kAddFriendNotification"
#define kAddFriendCancelNotification            @"kAddFriendCanceNotification"

#define kNotifyRegisterYZT                          @"kNotifyRegisterYZT"              //一账通注册
#define kNotifyYZTOTPSuccess                        @"kNotifyYZTOTPSuccess"            //一账通验证码已发
#define kNotifyYZTNeedNickName                      @"kNotifyYZTNeedNickName"          //一账通注册输入昵称
#define kNotifyYZTNeedConfirm                       @"kNotifyYZTNeedConfirm"           //一账通注册输入验证吗
#define kNotifyYZTNeedConfirm210                    @"kNotifyYZTNeedConfirm210"        //一账通注册输入验证吗
#define kNotifyYZTCancelRegister                    @"kNotifyYZTCancelRegister"

#define kNotifyTXTBindingSuccess                    @"kNotifyTXTBindingSuccess"        //天下通绑定成功
#define kNotifyTXTBindingError                      @"kNotifyTXTBindingError"          //天下通绑定失败
#define kNotifyModifyPersonalInformation            @"kNotifyModifyPersonalInformation"//修改个人信息完成

//删除群成员成功
#define kNotificationDeleteMemberSuccess            @"DeleteMemberSuccess"
//群消息通知
#define kNotificationOfAcceptRoom                   @"kAcceptRoomRequest"              //群邀请接受消息
#define kNotificationOfGetMemberInfo                @"getmemberinfo"                   //获取成员信息
#define kNotificationOfMemberBaseInfo               @"roommemberbaseinfo"              //获取群组精简信息
#define kNotificationOfGetDisscusionName            @"observerdisscussioname"          //监测讨论组名称
#define kNotificationOfGroupHeadImage               @"setgroupheadimage"               //设置群(讨论组)头像

#define kNotificationOfGroupHeadImageSuccess        @"setgroupheadimagesuccess"        //设置群(讨论组)头像成功
#define kNotificationUpdataGroupSuccess             @"UpdataGroupSuccess"              //升级为群成功

#define kNotificationOfChangeRoomNameSuccess        @"changeroomnamesuccss"            //群名称修改成功

#define kNotificationOfRoomMessageSwitch            @"roommessageswitch"                //群组消息回执

//更新进度
#define KUpdateGroupListProgress                    @"updateGroupListProgress"          //群列表更新
#define KUpdateGroupMemberProgress                  @"updateGroupMemberProgress"        //群成员消息
#define kUpdateLoadingIndicatorFromRoster           @"updateLoadingIndicatorFromRoster"

#define kNotificationSearchPublicIDSucccess         @"SearchPublicIDSucccess"           //查找公众帐号成功

#define kNotiBindingPhoneNumber                     @"notiBindingPhoneNumber"           //绑定手机号码短信发送成功
#define kNotiBindingPhoneNumberSuccess              @"notiBindingPhoneNumberSuccess"    //绑定手机号码成功
#define kNotiUNBindingPhoneNumberSuccess            @"notiUNBindingPhoneNumberSuccess"  //解除绑定手机号码成功
#define kNotiBindingPhoneNumberFail                 @"notiBindingPhoneNumberFail"       //绑定手机号码失败
#define kNotiPhoneNumberOccupied                    @"notiPhoneNumberOccupied"          //手机号被占用

#define kNotiBindingUsedPhoneNumber                 @"notiBindingUsedPhoneNumber"       //确认绑定已使用的手机号
#define kNotiBindingUsedPhoneNumberSuccess          @"notiBindingUsedPhoneNumberSuccess"//确认绑定已使用的手机号成功

//#define kNotiBindingYZT                             @"notiBindingYZT"                   //绑定一账通
#define kNotiBindingYZTSuccess                      @"notiBindingYZTSuccess"            //绑定一账通成功
#define kNotiBindingUsedYZT                         @"notiBindingUsedYZT"               //确定绑定一账通(一账通被占用的情况)
//#define kNotiunBindingYZT                           @"notiunBindingYZT"                 //解绑一账通
#define kNotiunBindingYZTSuccess                    @"notiunBindingYZTSuccess"          //解绑一账通成功


#define kNotificationOfChangRoomNickName            @"changeroomnicknamesuccess"        //修改群昵称成功
#define kNotificationOfChangRoomNickNameFail        @"changeroomnicknamefail"           //修改群昵称失败
#define kNotificationOfCreateRoomFail               @"createroomfail"                   //创建群组失败
#define kNotificationOfOutRoom                      @"outofroombyothers"                //自己被人踢出群组
#define kNotificationSelectedCountry                @"selectedCountry"                  //注册时选择国家
#define kNotificationSearchDeleteUserSuccess        @"kSearchDeleteUserSuccess"         //搜索删除好友成功

#pragma mark --注册、修改、忘记密码
#define nSendVerifyPhonenumberSuccess               @"SendVerifyPhonenumberSuccess"      //注册发送手机号成功
#define nSendVerifyPhonenumberFailed                @"SendVerifyPhonenumberFailed"       //注册发送手机号失败
#define nVerfiyPhoneNumberCodeSuccess               @"VerfiyPhoneNumberCodeSuccess"      //验证手机验证码成功
#define nVerfiyPhoneNumberCodeFailed                @"VerfiyPhoneNumberCodeFailed"       //验证手机验证码成功
#define nRegisterSuccess                            @"RegisterSuccess"                   //注册成功
#define nRegisterFailed                             @"RegisterFailed"                    //注册失败
#define nResetPasswordSuccess                       @"nResetPasswordSuccess"             //忘记密码 重置成功
#define nResetPasswordFaild                         @"nResetPasswordFaild"               //忘记密码 重置成功

#pragma mark --联系人
#define kNotifyPhoneContactState                    @"kNotifyPhoneContactState"          //通讯录匹配完成通知
#define kNotifyWebPhoneContactState                 @"kNotifyWebPhoneContactState"       //通讯录匹配完成通知
#define kNotifyPhoneNewAddContactState              @"kNotifyPhoneNewAddContactState"
#define kNotifyCancelRecord                         @"kNotifyCancelRecord"               //取消录音

#pragma mark --公众号
#define kGetPublicMenuSuccess                       @"kGetPublicMenuSuccess"             //查询公共帐号菜单成功
#define kGetPublicMenuFail                          @"kGetPublicMenuFail"                //查询公共帐号菜单失败
#define kNotifyGetPublicAccInfoFinish               @"kNotifyGetPublicAccInfoFinish"     //根据jid查询公众号信息
#define kNotifySubscribePublicAccountFinish         @"kNotifySubscribePublicAccFinish"   //关注、取消关注回调通知

#pragma mark --通讯协议
#define kNotificationPullOfflineMessage             @"kNotificationPullOfflineMessage"   //拉取离线消息的通知


#define kWltAppurlscheme      @"wltAppurlscheme"
#define kWltAppid             @"wltAppid"
#define kLanchImageUrl_key    @"LanchImageUrl"

#pragma mark --------------- xmpp消息id-------

//登录ios01
#define kLoginId                                    @"ios01LoginId"                            //登录消息(杜明芹)
#define kWanlitongLoginId                           @"ios01WanlitongLoginId"                   //万里通登录(杜明芹)
#define kOtpLoginGetCode                            @"ios01kOtpLoginGetCode"                   //otp登录获取验证码(杜明芹)
#define kLoginOutId                                 @"ios01LoginOutId"                         //退出登录消息(杜明芹)
#define kPersistId                                  @"ios01PersistId"                          //持续登录(杜明芹)
#define kYZTLoginId                                 @"ios01kYZTLoginId"                        //一账通登录(肖海波)
#define kYZTOTPId                                   @"ios01kYZTOTPId"                          //一账通校验OTP(肖海波)
#define kYZTRegisterFinished                        @"ios01kYZTRegisterFinished"               //一账通直接登录(肖海波)

//注册ios02
#define kRequestPhone                               @"ios02kRequestPhone"                      //注册发送手机号(杜明芹)
#define kVerfiyPhone                                @"ios02kVerfiyPhone"                       //注册验证验证码(杜明芹)
#define kRegisterUserId                             @"ios02registerUserId"                     //注册用户(杜明芹)
#define kCancelRegister                             @"ios02CancelRegister"                     //取消注册(杜明芹)
#define kYZTRegisterPhoneId                         @"ios02kYZTRegisterPhoneId"                //一账通注册手机号(肖海波)

//密码及绑定ios03
#define kActivatedUser                              @"ios03ActivatedUser"                      //群用户激活(杜明芹)
#define kResetPasswordId                            @"ios03ResetPasswordIdfailed"              //修改密码(杜明芹)
#define kReserPasswordIdfailed                      @"iosResetPasswordId"                      //修改密码失败
#define kForgetPasswordId                           @"ios03kForgetPasswordId"                  //忘记密码 重置密码(杜明芹)
#define kBindingPhoneNumber                         @"ios03bindingPhoneNumber"                 //绑定手机号(黄双南)
#define kCancelBindingPhoneNumber                   @"ios03cancelBindingPhoneNumber"           //解绑手机号(黄双南)
#define kChangeBindingPhoneNumber                   @"ios03changeBindingPhoneNumber"           //更换绑定手机号
#define kScarchBindingInfoMation                    @"ios03scarchBindingInfoMation"            //查询是否绑定密码/一账通/万里通(黄双南)
#define kValidationPassword                         @"ios03kValidationPassword"                //验证密码(黄双南)
#define kYZTRegisterConfirm                         @"ios03kYZTRegisterConfirm"                //一账通继续绑定(肖海波)
#define kNotiBindingYZT                             @"ios03notiBindingYZT"                     //绑定一账通(黄双南)
#define kNotiunBindingYZT                           @"ios03notiunBindingYZT"                   //解绑一账通(黄双南)
#define kSetTXTAccount                              @"ios03setTXTAccount"                      //设置天下通帐号(黄双南)
#define kAmendUserInfo                              @"ios03AmendUserInfo"                      //修改个人资料(黄双南)
//个人信息修改
#define kNotifyFinishedCountChange                  @"ios03knorifyfinishcountchange"       //修改个人信息成功
#define kNotifyCountChangeError                     @"ios03knorifycountchangeError"        //修改个人信息失败
#define kNotifyChangeOwnHeadImageSuccess            @"ios03ChangeOwnHeadImageSuccess"      //修改头像成功
#define kNotifyChangeOwnHeadImageFailed             @"ios03ChangeOwnHeadImageFailed"       //修改头像失败


//变更用户信息（手机联系人导入）ios04
#define kNewAddPhoneContact                         @"ios04kNewAddPhoneContact"                //新增手机联系人导入(肖海波)
#define kPhoneContact                               @"ios04PhoneContact"                       //手机联系人导入(肖海波)
#define kWebPhoneContact                            @"ios04WebPhoneContact"                    //web手机联系人导入(肖海波)
#define kLoginLastStep                              @"ios04kLoginLastStep"                     //注册导人通讯录导入(肖海波)
#define kNeedLoadContactsFriendData                 @"kNeedLoadContactsFriendData"             //导入手机联系人好友

//黑名单ios05
#define kBlackListId                                @"ios05BlackListId"                        //加入黑名单(钟礼文)
#define kBlackListConfirmId                         @"ios05BlackListConfirmId"                 //黑名单确定(钟礼文)
#define kRemoveBlackListID                          @"ios05RemoveBlackListID"                  //移出黑名单(钟礼文)
#define kRemoveBlackListConfirmId                   @"ios05RemoveBlackListConfirmId"           //移出黑名单确认消息(钟礼文)
#define kBlackSearchUserInfo                        @"ios05BlackSearchUserInfo"                //黑名单联系人详细信息(钟礼文)

//加好友ios06
#define kNewFriendSearchId                          @"ios06kNewFriendSearchId"                 //新朋友搜索id(雷志平)

//搜索以及查找用户信息ios07
#define kSearchNewUser                              @"ios07SearchNewUser"                      //从查找搜索用户(钟礼文)
#define kSearchUser                                 @"ios07SearchUser"                         //进入个人详细搜索用户(钟礼文)
#define kSecondSearchNewUser                        @"ios07secondSearchNewUser"                //收到好友请求后再次查询好友来获取model的ID(钟礼文)
#define kScanSearchUserInfo                         @"ios07scanSearchUserInfo"                 //二维码添加联系人
#define kSearchDeleteUser                           @"ios07kSearchDeleteUser"                  //查询来自与删除的好友聊天进入详细资料的ID(钟礼文)
#define kModifyFriendNickname                       @"ios07modifyFriendNickname"               //修改好友备注名(钟礼文)

//创建群ios08
#define kOfflineMessageID                           @"ios08messageidofoffline"                 //获取离线消息(何广忠)
#define MESSAGE_GETROOMLIST                         @"ios08getroomlist"                        //获取群列表ID(何广忠)
#define MESSAGE_SETROOMHEADIMAGE                    @"ios08setroomheadimage"                   //设置群头像ID(何广忠)
#define MESSAGE_CHANGEROOMNAME                      @"ios08message_roomnamechange"             //群名称修改ID(何广忠)
#define MESSAGE_GETROOMMEMBER                       @"ios08getroommember"                      //获取群成员ID(何广忠)
#define MESSAGE_GETROOMID                           @"ios08getroomid"                          //获取群ID(何广忠)
#define MESSAGE_SETTINGID                           @"ios08settingID"                          //配置群ID(何广忠)
#define MESSAGE_SWITCH                              @"ios08messageswitch"                    //群消息通知开关
#define MESSAGE_GETBASEINFO                         @"ios08getroombaseinfo"                  //获取群精简信息

//公众号ios09
#define kGetMyPublicAccList                         @"ios09getMyPublicAccList"                  //获取关注公众帐号列表(马勤)
#define KGetEnablePublicAccList                     @"ios09getEnablePublicAccList"              //获取禁用公众账号列表(马勤)




#define kSubscribePublicAccount                     @"ios09subscribePublicAccount"              //关注公众帐号(马勤)
#define kGetPublicAccInfo                           @"ios09getPublicAccInfo"                    //根据jid获取公众号信息(麦舒凯)

//#define kLoginId                                    @"LoginId"                            //登录消息
//#define kWanlitongLoginId                           @"WanlitongLoginId"                   //万里通登录
//#define kOtpLoginGetCode                            @"kOtpLoginGetCode"                   //otp登录获取验证码
//#define kLoginOutId                                 @"LoginOutId"                         //退出登录消息
//#define kPersistId                                  @"PersistId"                          //持续登录
//#define kBlackListId                                @"BlackListId"                        //加入黑名单
//#define kBlackListConfirmId                         @"BlackListConfirmId"                 //黑名单确定
//#define kRemoveBlackListID                          @"RemoveBlackListID"                  //移出黑名单
//#define kRemoveBlackListConfirmId                   @"RemoveBlackListConfirmId"           //移出黑名单确认消息
#define kSearchFriendInfoId                         @"kFriendDetailInfoId"                //好友详细详情
//#define kRequestPhone                               @"kRequestPhone"                      //注册发送手机号
//#define kVerfiyPhone                                @"kVerfiyPhone"                       //注册验证验证吗
//#define kRegisterUserId                             @"registerUserId"                     //注册用户
#define kRegisterLogin                              @"RegisterLogin"                      //已经注册过的直接登录
//#define kCancelRegister                             @"CancelRegister"                     //取消注册
//#define kActivatedUser                              @"ActivatedUser"                      //群用户激活
//#define kResetPasswordId                            @"ResetPasswordId"                    //修改密码
//#define kForgetPasswordId                           @"kForgetPasswordId"                  //忘记密码 重置密码
//#define kValidationPassword                         @"kValidationPassword"                //验证密码


//#define kSearchUser                                 @"SearchUser"                //搜索用户
#define kSearchRoomUser                             @"SearchRoomUser"            //搜索群组用户

//#define kBlackSearchUserInfo                        @"BlackSearchUserInfo"       //黑名单联系人详细信息

//#define kSearchNewUser                              @"SearchNewUser"             //从查找搜索用户
//#define kSecondSearchNewUser                        @"secondSearchNewUser"       //收到好友请求后再次查询好友来获取model
#define kStrangerSearch                             @"kStrangerSearch"           //从手机通讯录查找搜索用户
//#define kSearchDeleteUser                           @"kSearchDeleteUser"         //查询来自被删除的好友


//#define kNewAddPhoneContact                         @"kNewAddPhoneContact"       //新增联系人
//#define kPhoneContact                               @"PhoneContact"              //手机联系人
//#define kAmendUserInfo                              @"AmendUserInfo"             //修改个人资料
//#define kWebPhoneContact                            @"WebPhoneContact"           //web手机联系人
//#define kLoginLastStep                              @"kLoginLastStep"            //注册导人通讯录
#define kChangeOwnHeadImage                         @"ChangeOwnHeadImage"        //注册成功上传头像成功后修改个人头像

#define getTokenId                                  @"GetTokenId"                //上传文件
#define TokenForUpload_OTHER                        @"TokenForUpload_OTHER"      //上传文件token 其它文件
#define TokenForUpload_IMAGE                        @"TokenForUpload_IMAGE"      //上传文件token 图片
#define TokenForUpload_VOICE                        @"TokenForUpload_VOICE"      //上传文件token 音频
#define TokenForUpload_VEDIO                        @"TokenForUpload_VEDIO"      //上传文件token 视频
#define TokenForUpload_HEAD                         @"TokenForUpload_HEAD"       //上传文件token 视频

#define kSeverUploadToken                           @"TokenForUpload"            //上传文件token
#define kSeverDownloadToken                         @"kSeverDownloadToken"       //下载文件token
#define kIOSOpenInternational                       @"IOS_isOpenInternational"   //是否开启国际号码登录注册
#define kShowBackOtherAppBtn                        @"ShowBackOtherAppBtn"      //是否显示返回其它app按钮
#define kPaiphoneBankApp_Url                        @"PAiPhoneBank://com.pingan.paiphonebank?appFrom=patxt"//口袋银行app的URL
#define kWanltApp_Url                               @"pawlt://com.pingan.pawlt"//万里通app的URL
//群消息ID类别
//#define MESSAGE_GETROOMLIST         @"getroomlist"                      //获取群列表ID
//#define MESSAGE_GETROOMMEMBER       @"getroommember"                    //获取群成员ID
#define MESSAGE_ROOMTIREN           @"roomtiren"                        //群主踢人
//#define MESSAGE_GETROOMID           @"getroomid"                        //获取群ID
#define MESSAGE_CREATEID            @"createID"                         //创建群的消息ID
//#define MESSAGE_SETTINGID           @"settingID"                        //配置群ID
#define MESSAGE_ADDGUYSID           @"addGuysID"                        //添加好友入群ID
#define MESSAGE_ADDRESULTREFUSE     @"addResultRefuse"                  //群邀请拒绝结果ID
#define MESSAGE_ADDRESULTACCEPT     @"addResultAccept"                  //群邀请接受结果ID
#define MESSAGE_ROOMTABLE           @"getRoomTable"                     //群列表ID
#define MESSAGE_CHANGEROOMNAMEIQ    @"message_roomnamechangerequest"    //群名称修改配置请求ID
//#define MESSAGE_CHANGEROOMNAME      @"message_roomnamechange"           //群名称修改ID
#define MESSAGE_CHANGEROOMNICK      @"message_roomnickname"             //群昵称修改
#define MESSAGE_GETROOMHEADIMAGE    @"getroomheadimage"                 //获取群头像ID
//#define MESSAGE_SETROOMHEADIMAGE    @"setroomheadimage"                 //设置群头像ID
#define MESSAGE_OUTOFROOM           @"outofroom"                        //退出群(讨论组)ID
#define kGroupDetailSuccess         @"notificationGroupDetailSuccess"   //全量获取群成员列表成功(通知GroupDetail刷新界面)
#define kGroupDetailError           @"notificationGroupDetailError"     //全量获取群成员列表失败(通知GroupDetail刷新界面)

#define kNotifySetProfile           @"kNotifySetProfile"                //通知设者头像
#define kNotifyHadSetProfile        @"kNotifyHadSetProfile"             //通知设者头像kNotifyHadSetProfile
//
//#define kYZTLoginId                 @"kYZTLoginId"                      //一账通登录
//#define kYZTRegisterPhoneId         @"kYZTRegisterPhoneId"              //一账通注册手机号
//#define kYZTOTPId                   @"kYZTOTPId"                        //校验OTP
//#define kYZTRegisterFinished        @"kYZTRegisterFinished"             //校验OTP
//#define kYZTRegisterConfirm         @"kYZTRegisterConfirm"
#define kGetPublicAlbum             @"kGetPublicAlbum"                  //获取公众帐号的头像信息
#define kPayLoginId                 @"kPayLoginId"                      //支付登录
#define kSearchCount                @"SearchCount"                      //搜索个人信息

/*==================================用户信息===========================================*/
#define resourceType                            @"iphone"               //区分resourceType用不同的推送模版
#define kLoginSuccess_Last                      @"LoginSuccess"            //前一次天下通登录
#define kLoginSuccessBindUm                     @"LoginSuccessBindUm"      //登录成功是否绑定um
#define kLoginSuccess_Last_userName             @"LoginSuccess_userName"   //前一次天下通登录用户名
#define kYZTLoginSuccess_Last                   @"kYZTLoginSuccess_Last"   //前一次一账通登录
#define kPayLoginSuccess_Last                   @"kPayLoginSuccess_Last"   //前一次支付登录
#define kLastLoginAccount                       @"kLastLoginAccount"       //上次登录帐户
#define kLastLoginUserInfo                      @"kLastLoginUserInfo"      //上次登录用户的信息 用于持续登录

#define kTrendsViewDefault_bg_imgUrl1 @"http://pinganimg.u.qiniudn.com/friendcircle_default_bg_1.jpg"
#define kTrendsViewDefault_bg_imgUrl2 @"http://pinganimg.u.qiniudn.com/friendcircle_default_bg_2.jpg"
#define kTrendsViewDefault_bg_imgUrl3 @"http://pinganimg.u.qiniudn.com/friendcircle_default_bg_3.jpg"

#define kProvider                  @"qiniu"   //云存储提供商	"""pingan""平安自己搭建(默认),""qiniu""七牛公司,""yupoo""又拍公司"
#define kSearchPublicCardID        @"searchpublicid"                    //查询公众帐号
#define kUploadTokenDeadDate 14                                         //token有效时间，过期则重新请求
//#define kSetTXTAccount             @"setTXTAccount"                     //设置天下通帐号
#define kScanSearchPublicAccunt    @"ScanSearchPublicAccunt"            //扫描公众帐号
#define kGetPublicAccProfile       @"getPublicAccProfile"               //获取公众帐号头像
//#define kGetMyPublicAccList        @"getMyPublicAccList"                //获取关注公众帐号列表



//#define KGetEnablePublicAccList    @"getEnablePublicAccList"            //获取禁用公众账号列表

//#define kSubscribePublicAccount    @"subscribePublicAccount"            //关注公众帐号

#define KWebSubscribeCreditCardPublicAccount   @"subscribeWebCreditCardPublicAccount"  //web关注公众号
#define KWebUnsubscribeCreditCardPublicAccount @"unSubscribeWebCreditCardPublicAccount" //web取消

#define kSubscribeCreditCardPublicAccount @"subscribeCreditCardPublicAccount"  //关注信用卡公众账号(活动界面专用)

#define kNewSubscribePublicAccount @"kNewSubscribePublicAccount"        //关注公众账号 找平安

#define kUnsubscribePublicAccount  @"unsubscribePublicAccount"          //取消关注公众帐号
//#define kBindingPhoneNumber        @"bindingPhoneNumber"                //绑定手机号

//#define kCancelBindingPhoneNumber  @"cancelBindingPhoneNumber"          //解绑手机号
//#define kModifyFriendNickname      @"modifyFriendNickname"              //修改好友备注名
//#define kScarchBindingInfoMation   @"scarchBindingInfoMation"           //查询是否绑定密码/一账通/万里通
#define kScarchBindingInfoMationSuccess   @"scarchBindingInfoMationSuccess"   //查询是否绑定密码/一账通/万里通成功

#define kLogoOnFailed_disConnect   @"LogoOnFailed_disConnect"


//#define kDownloadSmall             @"small"                             //获取图片缩略图 100*100
#define kDownloadSmall             @"small360"                          //获取图片缩略图 360*360
#define kDownloadVsetSmall         @"vset_small"                        //获取视频缩略图 100*100
#define kDownloadiPhoneHigh        @"iphone_high"                       //获取mp4格式视频
#define kDownloadiPadHigh          @"ipad_high"                         //获取mp4格式视频
#define kDownloadVimage          @"vimage100"                         //获取mp4格式视频

#pragma mark - 通知

#define nSendVerifyPhonenumberSuccess       @"SendVerifyPhonenumberSuccess"  //注册发送手机号成功
#define nSendVerifyPhonenumberFailed        @"SendVerifyPhonenumberFailed"   //注册发送手机号失败
#define nVerfiyPhoneNumberCodeSuccess       @"VerfiyPhoneNumberCodeSuccess"  //验证手机验证码成功
#define nVerfiyPhoneNumberCodeFailed        @"VerfiyPhoneNumberCodeFailed"   //验证手机验证码成功

#define kMyQRcode                           @"myQRcode"                      //标识我的二维码
#define kLastRegisterNum                    @"LastRegisterNum"               //上次注册的手机号

#define kNetworkDisconnect                  @"kNetworkDisconnect"            //查询是否绑定密码/一账通/万里通
#define kNetworkConnected                   @"kNetworkConnected"
#define kNetworkConnecting                  @"kNetworkConnecting"
#define kFirstLogin                         @"kFirstLogin"                   //第一次登录
#define kNotifiLogout                       @"NotifiLogout"               //退出登录成功
#define kApplicationTerminateNotification   @"kApplicationTerminateNotification"  //程序结束保存数据
#define kShowGropInfo                       @"ShowGropInfo"                       //显示群组
#define kValidTime 60                                                    //重新获取验证码的时间
#define kNotifyGotoSetAlbumUrl              @"kNotifyGotoSetAlbumUrl"    //前往设置头像
#define kNotifyGotoActivePage               @"NotifyGotoActivePage"      //前往活动页

#define kNotifyTrendsBadgeNumberRefreshed   @"kNotifyTrendsBadgeNumberRefreshed" //新动态badge

#define kIsSynchronizeMember                @"kIsSynchronizeMember"         //同步更新的标志位
#define kExistNewJoinGroup                  @"kExistNewJoinGroup"           //存在新加群的消息
#define kUserClickContacts                  @"kUserClickContacts"           //用户点击联系人标识
#define kIsPullOfflineMessage               @"kIsPullOfflineMessage"        //是否正在拉取离线消息


/*=====================热门活动=======================*/
#define kNotifyFetRecommendSuccess          @"fetRecommendSuccess"    //获取活动信息成功
#define kNotifyFetRecommendDBURLSuccess     @"fetRecommendDBURLSuccess" //获取活动DB URL成功
#define kNotifyFetRecommendSuccess_other    @"fetRecommendSuccess_other"//获取活动信息成功后通知报名处理
#define kSavePublicProfile @"kSavePublicProfile"                        //查询信用卡公众号
#define kSaveCreditCardAttentionSuccess @"SaveCreditCardAttentionSuccess"  //保存信用卡公众号成功
#define kAttentionCreditCardSuccess @"AttentionCreditCardSuccess"  //查询公众号成功(信用卡)
#define kAttentionCreditCard_Failed    @"AttentionCreditCard_Failed"   //关注信用卡公众号失败
#define kNotifyFetFinanceCircleDataSuccess   @"fetFinanceCircleDataSuccess"//获取金融圈数据成功

#define kSendVodioRequest       @"kSendVodioRequest"                  //发送视频请求
#define kSendRejectVodioRequest @"kSendRejectVodioRequest"            //拒绝视频请求
#define kSendAcceptVodioRequest @"kSendAcceptVodioRequest"            //接受视频请求
#define kSendSipRegisterSuccess @"kSendSipRegisterSuccess"            //电话注册成功
#define kSendHeartVedio         @"kSendHeartVedio"                    //视频心跳
#define kSendCloseVodio         @"kSendCloseVodio"                    //关闭视频

#define kNotifyFeedBackMessageInsert         @"kNotifyFeedBackMessageInsert"   //插入意见反馈消息
#define kNotifyOfflineMessageOver            @"kNotifyOfflineMessageOver"             //离线消息获取完通知

#define MYJID_BARE [Tools getMyJIDBare]
//精简拉取好友
#define  sycnRoster @"sycnRoster"
#define  kNewRosterDetail @"kNewRosterDetail"
#define lastFetchRosterDate @"LastFetchRosterDate"

#define kNotifyPhoneContactStateRefreshed @"kNotifyPhoneContactStateRefreshed"
#define kNotifyOfflineMessageStart @"kNotifyOfflineMessageStart"
#define kNotifyOfflineMessageOver @"kNotifyOfflineMessageOver"

//loginSession无效的通知,主要应用于（设备被挤下线的情况）
#define  kLoginSessionUnvariable    @"LoginSessionUnvariable"
/*=====================微信，微博URL=======================*/
#define WEIXIN_URL  @"wx805a983cd8bb6d60"
#define WEIBO_URL   @"274254638"

/*=====================群相关的Tag=====================*/
#define kGroupMemberRequestTag                 2001     //第一次登录进行同步时使用的Tag，便于计算进度
#define kGroupMemberOtherRequestTag            2002     //除上述以外的请求都用此Tag
#define kGroupMemberResiter                    2003     //注册时UM验证获取预置群组群成员

/*======================================https请求错误提示码==========================================*/
#define paramError                          602                           //参数错误
#define phoneNumFormatError                 608                           //电话号码格式非法
#define validateCodeError                   622                           //短信验证码错误
#define ValidateCodeInvalid                 623                           //验证码失效
#define UserNotExist                        605                           //用户不存在（还未注册天下通）
#define PasswordError                       617                           //密码错误
#define serverDubboNotAvaiable              500                           //服务器端暂时不可用
#define operatingFrequencyTooFast           888                           //错误验证码输入次数过多
#define operatingFrequencyAccountLocked     889                           //错误验证码输入次数过多，账号被锁定
/*=====================TAG  VALUE=======================*/
#define searchUserFromSearchTag 2014080101
#define scanSearchUserTag 20140812
#define searchUerInfoTag  2014081201

/*=========朋友圈首页浏览位置===========*/
#define kFRIENDCIRCLECONTENTY @"fccontentY"
#define kFRIENDCIRCLECELL @"FRIENDCIRCLECELL"

typedef enum{
    PROTO_SEND,            //发
    PROTO_RECEIVE          //收
}MSG_PROTO;                //发送、接收标志

typedef enum {
    into_Login = 1,//正常登录
    into_Persist  //持续登录 token过期
} Into_Type;
//消息类型定义
typedef enum {
    MESSAGE_TEXT,           //普通文本消息 0
    MESSAGE_IMAGE,          //图片消息 1
    MESSAGE_VOICE,          //语音消息 2
    MESSAGE_VIDEO,          //视频消息 3
    MESSAGE_LOCATIONIMAGE,  //地理位置消息 4
    MESSAGE_FRIENDCARD,     //名片消息 5
    MESSAGE_DYNADICFACE,    //动态表情 6
    MESSAGE_PUBLICAD,       //公共帐号广告 7
    MESSAGE_MENUEVENT,      //公共菜单操作命令 8
    MESSAGE_HYPERLINK,      //带超链接的文本消息 9
    MESSAGE_WEBVIEW,        //webview显示链接 10
    MESSAGE_PROMPT,         //提示消息加入群等
    MESSAGE_TEMPLATE,       //模板消息 12
    MESSAGE_SINGLE,         //单图文消息 13
    MESSAGE_TESTGAME,       //测试游戏 14
    MESSAGE_ORDER,          //出单消息 15
    MESSAGE_CONGRATS,       //发送祝福消息 16
    MESSAGE_BIRTHDAY,       //生日祝福消息/新人入司 17
    MESSAGE_ASKLICAI,       //问理财消息 18
   
} MESSAGE_TYPE;

typedef enum{
    COMMENT_SELF,          //自己的评论
    COMMENT_OTHERS,        //他人的评论
} COMMENT_TYPE;

//消息发送状态类型定义
typedef enum {
    MESSAGE_STATE_Normal = 0,
    MESSAGE_SENDING=1,      //消息发送中
    MESSAGE_SUCCESS,        //消息发送成功
    MESSAGE_FAILED          //消息发送失败
} MESSAGE_STATE;


//消息已读状态类型定义
typedef enum {
    MESSAGE_READ,               //消息已读
    MESSAGE_UNREAD,             //消息未读
    MESSAGE_AUDIO_UNREAD        //语音消息未读
} READ_STATE;


typedef enum{
    CHAT,                    //点对点聊天
    GROUP_CHAT,              //群聊
    DISCUSSION,              //讨论组
    PUBLIC,                  //公众帐号,或者固定群
    PUBLIC_MENU,             //公众帐号（特殊键盘）
}CHAT_TYPE;

typedef enum
{
    GROUP_NOTIFY_ONLINE_MESSAGE, //在线消息
    GROUP_NOTIFY_OFFLINE_MESSAGE //离线消息
}GROUP_NOTIFY_MESSAGE_TYPE;

//联系人类型
typedef enum {
    FRIEND_ISBLACKED,        //黑名单联系人
    FRIEND_ISNORMAL,         //正常联系人
    FRIEND_ISDELETED,         //联系人已被删除
    FRIEND_ISUNKOWN           //未知联系人
}FRIEND_TYPE;

//数据库操作动作
typedef enum
{
    DAO_ADD,                //新增
    DAO_MODIFY,             //修改
    DAO_DELETE              //删除
}DAOACTION_TYPE;


typedef enum {
    LoginType_PhoneNumber,   //手机号登录
    LoginType_XinNumber,     //心号
    LoginType_PersistLogin,  //持续登录
    LoginType_Jid,           //Jid登录
    LoginType_YZT,           //一账通登录
    LoginType_OTP,           //手机otp登录
    LoginType_PAY,           //支付登录
    LoginType_Wanlitong,       //万里通登录
    LoginType_Connected,     //只连接不登录
} LoginType;

typedef enum {
    LoginFrom_PhoneNumber,   //手机号登录
    LoginFrom_XinNumber,     //心号
    LoginFrom_PersistLogin,  //持续登录
    LoginFrom_Jid,           //Jid登录
    LoginFrom_YZT,           //一账通登录
    LoginFrom_OTP,           //手机otp登录
    LoginFrom_PAY,           //支付登录
    LoginFrom_Wanlitong,       //万里通登录
    LoginFrom_Connected,     //只连接不登录
    LoginFRom_Unknow         //默认未知
    //
} LoginFrom;


typedef enum { //上传时使用:0其它,1图片，2音频，3视频
    FileType_OTHER,
    FileType_IMAGE,
    FileType_VOICE,
    FileType_VEDIO
}FileType;

typedef enum { //上传时使用:0普通文件，1头像
    BizType_NOMAL,
    BizType_HEADIMAGE,
}BizType;

//用于识别从哪里进入联系人详细
typedef enum {
    Detail_Normal=0,
    Detail_Search,
    Detail_Stranger,
} Detail_Type;

//用于识别是否朋友关系
typedef enum{
    Friend_BothNormal=0,
    Friend_BothBlack,
    Friend_None,
}Friend_Relationship;

//键盘的类型
typedef enum{
    FaceToolType_Normal=0,      //普通键盘
    FaceToolType_Public,        //公众帐号键盘
    FaceToolType_Order,         //出单消息键盘
    FaceToolType_Birthday,      //生日祝福键盘
    FaceToolType_WelcomeNew,    //新人入司键盘
}FaceToolType;

//新朋友类型
typedef enum
{
    NewUserState_noAdd = 1,     //加为好友
    NewUserState_no,            //等待验证
    NewUserState_yes,           //通过验证
    NewUserState_alreadyAdd,    //已添加
    
}NewUserState;

//好友来源
typedef enum{
	FriendFromType_Normal = 0,   // 默认值
    FriendFromType_Contact =1,   //来自手机通讯录   1
    FriendFromType_Scan,        //来自扫一扫       2
    FriendFromType_Search,       //来自搜索        3
	FriendFromType_Group,       //  来自群聊       4
	FriendFromType_E_Friend,    // 橙E好友         5
    FriendFromType_Nearby, //附近的人    6
    FriendFromType_Birthday,    //同月同日生日      7
    FriendFromType_MeanwhileWork,//同年月同月同日入公司 8
    FriendFromType_Schoolfellow,//校友             9
    FriendFromType_Fellow,      //老乡 10
    FriendFromType_CommonGroup, //群友       11
    FriendFromType_CommonFriends,//共同好友  12
	FriendFromType_Max
}FriendFromType;

//手机通讯录
typedef enum
{
    phoneUserState_noAdd,       //未添加,
    phoneUserState_noInvite,    //未开通，邀请
    phoneUserState_alreadyAdd,  //已添加
    phoneUserState_wait,        //等待验证
    phoneUserState_unkown,      //
}PhoneUserState;

//手机otp类型
typedef enum
{
    Otp_Register,               //注册
    Otp_ResetPassword,          //重置密码
}PhoneOtpType;

//绑定手机Otp类型
typedef enum
{
    OTP_PhoneBinding = 1,       //绑定手机号
    OTP_ChangePhonBinding,      //更换绑定手机号
    OTP_CancelPhoneBinding,     //解绑手机号
    OTP_NotVerify               //手机号未验证
}BindingPhoneOTP;

//一账通绑定
typedef enum{
    BindTypeYZT_NO,
    BindTypeYZT_YES
}BindTypeYZT;


typedef enum {
    Message_Normal=1,           //正常
    Message_Relay =2,           //转发
    Message_Conversation =3,    //会话
    Message_SearchResult =4,    //搜索
} Message_From_Type;

//被拉黑后发送消息的提示
typedef enum
{
    MessageTip_Normal=1,
    MessageTip_Black
}MessageTip_Type;

//一账通登录
typedef enum _YZTInputNickNameType {
	from_register = 0,          //使用非一账通手机号首次注册
    from_bind = 1,              //继续绑定
    from_yztmobileRegister      //使用一账通手机号首次注册
} YZTInputNickNameType;

//新人菜单的类型
typedef enum{
    welcomeNewBarType_congrats=0,   //新人祝贺
    welcomeNewBarType_share,        //新人感言分享
    welcomeNewBarType_both,         //祝贺＋分享
}WelcomeNewBarType;

//出单菜单的类型
typedef enum{
    orderBarType_congrats=0,   //出单祝贺
    orderBarType_share,        //出单经验分享
    orderBarType_both,         //祝贺＋分享
}OrderBarType;

//网络请求参数数据类型
typedef enum {
    Post_JSON,
    Post_String
}POST_TYPE;

//用户系统来源
typedef enum {
    TXTuser = 10000,//天下通用户
    YZTuser = 10001,//一帐通用户
    WLTuser = 10002,//万里通用户
}Usersource;
//申请验证码类型
typedef enum {
    register_sms = 1, //注册
    login_sms = 2,//登录
    bingdingphoneNum_sms = 3,//手机绑定
    changeBingdingNum_sms = 4,//更改手机号绑定
    forgetPassWord_sms = 6,//忘记密码
    
}SmsType;

//网络请求HTTP类型
typedef enum
{
    HTTP = 1,//普通http请求（明文发送明文返回）
    HTTP_V2,//V2版本http请求（压缩加密发送，解密解压返回）
    HTTPS,//只用于第一次登录
    HTTP_RSA,//只用于http持续登录
}HTTP_TYPE;



typedef enum
{
    TCP_MODE = 1, //Http请求发送消
    HTTP_MODE,      //用TCP 发送消息
    PING_MODE,
}SEND_MESSAGE_MODE;



#endif
