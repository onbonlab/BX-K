# 错误码及说明

动态库中每个接口函数最后都返回函数执行结果，用户可根据函数执行结果查找判断该函数的执行情况。

### 错误状态

| 错误名称             | 代码 | 说明                                            |
| -------------------- | ---- | ----------------------------------------------- |
| ERR_NO               | 0    | 没有错误                                        |
| ERR_OUTOFGROUP       | 1    | Command Group Error                             |
| ERR_NOCMD            | 2    | Command Not Found                               |
| ERR_BUSY             | 3    | The Contorller is busy now                      |
| ERR_MEMORYVOLUME     | 4    | Out of the Memory Volume                        |
| ERR_CCHECKSUM        | 5    | CRC16 Checksum Error                            |
| ERR_FILENOTEXIST     | 6    | File Not Exist                                  |
| ERR_FLASH            | 7    | Flash Access Error                              |
| ERR_FILE_DOWNLOAD    | 8    | File Download Error                             |
| ERR_FILE_NAME        | 9    | File Name Error                                 |
| ERR_FILE_TYPE        | 10   | File Type Error                                 |
| ERR_FILE_CRC16       | 11   | File CRC16 Error                                |
| ERR_FONT_NOT_EXIST   | 12   | Font Library Not Exist                          |
| ERR_FIRMWARE_TYPE    | 13   | Firmware Type Error (Check the controller type) |
| ERR_DATE_TIME_FORMAT | 14   | Date Time format error                          |
| ERR_FILE_EXIST       | 15   | File Exist for File overwrite                   |
| ERR_FILE_BLOCK_NUM   | 16   | File block number error                         |
| ERR_COMMUNICATE      | 100  | 通信失败                                        |
| ERR_PROTOCOL         | 101  | 协议数据不正确                                  |
| ERR_TIMEOUT          | 102  | 通信超时                                        |
| ERR_NETCLOSE         | 103  | 通讯断开                                        |
| ERR_INVALID_HAND     | 104  | 无效句柄                                        |
| ERR_PARAMETER        | 105  | 参数错误                                        |
| ERR_SHOULDREPEAT     | 106  | 需要重复上次的错误包                            |
| ERR_FILE             | 107  | 无效文件                                        |