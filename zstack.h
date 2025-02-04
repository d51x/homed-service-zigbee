#ifndef ZSTACK_H
#define ZSTACK_H

#define ZSTACK_CONFIGURATION_MARKER                 0x42
#define ZSTACK_CLEAR_DELAY                          4000
#define ZSTACK_REQUEST_TIMEOUT                      10000

#define ZSTACK_SKIP_BOOTLOADER                      0xEF
#define ZSTACK_PACKET_FLAG                          0xFE
#define ZSTACK_COORDINATOR_STARTED                  0x09

#define PERMIT_JOIN_MODE_ADDREESS                   0x0F
#define PERMIT_JOIN_BROARCAST_ADDRESS               0xFFFC

#define AF_ACK_REQUEST                              0x10
#define AF_DISCV_ROUTE                              0x20
#define AF_EN_SECURITY                              0x40
#define AF_SKIP_ROUTING                             0x80
#define AF_DEFAULT_RADIUS                           0x0F

#define SYS_VERSION                                 0x2102
#define SYS_OSAL_NV_ITEM_INIT                       0x2107
#define SYS_OSAL_NV_READ                            0x2108
#define SYS_OSAL_NV_WRITE                           0x2109
#define AF_REGISTER                                 0x2400
#define AF_DATA_REQUEST                             0x2401
#define AF_DATA_REQUEST_EXT                         0x2402
#define AF_INTER_PAN_CTL                            0x2410
#define ZDO_NODE_DESC_REQ                           0x2502
#define ZDO_SIMPLE_DESC_REQ                         0x2504
#define ZDO_ACTIVE_EP_REQ                           0x2505
#define ZDO_BIND_REQ                                0x2521
#define ZDO_UNBIND_REQ                              0x2522
#define ZDO_MGMT_LQI_REQ                            0x2531
#define ZDO_MGMT_LEAVE_REQ                          0x2534
#define ZDO_MGMT_PERMIT_JOIN_REQ                    0x2536
#define ZDO_MSG_CB_REGISTER                         0x253E
#define ZDO_STARTUP_FROM_APP                        0x2540
#define ZB_READ_CONFIGURATION                       0x2604
#define ZB_WRITE_CONFIGURATION                      0x2605
#define UTIL_GET_DEVICE_INFO                        0x2700
#define APP_CNF_BDB_SET_CHANNEL                     0x2F08

#define SYS_RESET_REQ                               0x4100
#define SYS_RESET_IND                               0x4180
#define AF_DATA_CONFIRM                             0x4480
#define AF_INCOMING_MSG                             0x4481
#define AF_INCOMING_MSG_EXT                         0x4482
#define ZDO_NODE_DESC_RSP                           0x4582
#define ZDO_SIMPLE_DESC_RSP                         0x4584
#define ZDO_ACTIVE_EP_RSP                           0x4585
#define ZDO_BIND_RSP                                0x45A1
#define ZDO_UNBIND_RSP                              0x45A2
#define ZDO_MGMT_LQI_RSP                            0x45B1
#define ZDO_MGMT_LEAVE_RSP                          0x45B4
#define ZDO_MGMT_PERMIT_JOIN_RSP                    0x45B6
#define ZDO_MGMT_NWK_UPDATE_RSP                     0x45B8
#define ZDO_STATE_CHANGE_IND                        0x45C0
#define ZDO_END_DEVICE_ANNCE_IND                    0x45C1
#define ZDO_SRC_RTG_IND                             0x45C4
#define ZDO_CONCENTRATOR_IND                        0x45C8
#define ZDO_LEAVE_IND                               0x45C9
#define ZDO_TC_DEV_IND                              0x45CA
#define ZDO_PERMIT_JOIN_IND                         0x45CB
#define ZDO_MSG_CB_INCOMING                         0x45FF
#define APP_CNF_BDB_COMMISSIONING_NOTIFICATION      0x4F80

#define ZCD_NV_STARTUP_OPTION                       0x0003
#define ZCD_NV_MARKER                               0x0060
#define ZCD_NV_PRECFGKEY                            0x0062
#define ZCD_NV_PRECFGKEYS_ENABLE                    0x0063
#define ZCD_NV_PANID                                0x0083
#define ZCD_NV_CHANLIST                             0x0084
#define ZCD_NV_LOGICAL_TYPE                         0x0087
#define ZCD_NV_ZDO_DIRECT_CB                        0x008F
#define ZCD_NV_TCLK_TABLE                           0x0101

#include "adapter.h"

#pragma pack(push, 1)

struct versionResponseStruct
{
    quint8  transport;
    quint8  product;
    quint8  major;
    quint8  minor;
    quint8  patch;
    quint32 build;
};

struct registerEndpointRequestStruct
{
    quint8  endpointId;
    quint16 profileId;
    quint16 deviceId;
    quint8  version;
    quint8  latency;
};

struct permitJoinRequestStruct
{
    quint8  mode;
    quint16 dstAddress;
    quint8  duration;
    quint8  significance;
};

struct dataRequestStruct
{
    quint16 networkAddress;
    quint8  dstEndpointId;
    quint8  srcEndpointId;
    quint16 clusterId;
    quint8  transactionId;
    quint8  options;
    quint8  radius;
    quint8  length;
};

struct extendedDataRequestStruct
{
    quint8  dstAddressMode;
    quint64 dstAddress;
    quint8  dstEndpointId;
    quint16 dstPanId;
    quint8  srcEndpointId;
    quint16 clusterId;
    quint8  transactionId;
    quint8  options;
    quint8  radius;
    quint16 length;
};

struct setChannelRequestStruct
{
    quint8  isPrimary;
    quint32 channel;
};

struct nvReadRequestStruct
{
    quint16 id;
    quint8  offset;
};

struct nvReadReplyStruct
{
    quint8  status;
    quint8  length;
};

struct nvInitRequestStruct
{
    quint16 id;
    quint16 itemLength;
    quint8  dataLength;
};

struct nvWriteRequestStruct
{
    quint16 id;
    quint8  offset;
    quint8  length;
};

struct readConfigurationReplyStruct
{
    quint8  status;
    quint8  id;
    quint8  length;
};

struct writeConfigurationRequestStruct
{
    quint8  id;
    quint8  length;
};

struct dataConfirmStruct
{
    quint8  status;
    quint8  endpointId;
    quint8  transactionId;
};

struct incomingMessageStruct
{
    quint16 groupId;
    quint16 clusterId;
    quint16 srcAddress;
    quint8  srcEndpointId;
    quint8  dstEndpointId;
    quint8  broadcast;
    quint8  linkQuality;
    quint8  security;
    quint32 timestamp;
    quint8  transactionId;
    quint8  length;
};

struct extendedIncomingMessageStruct
{
    quint16 groupId;
    quint16 clusterId;
    quint8  srcAddressMode;
    quint64 srcAddress;
    quint8  srcEndpointId;
    quint16 srcPanId;
    quint8  dstEndpointId;
    quint8  broadcast;
    quint8  linkQuality;
    quint8  security;
    quint32 timestamp;
    quint8  transactionId;
    quint16 length;
};

struct deviceLeaveStruct
{
    quint16 networkAddress;
    quint64 ieeeAddress;
    quint8  request;
    quint8  remove;
    quint8  rejoin;
};

struct zdoMessageStruct
{
    quint16 srcAddress;
    quint8  broadcast;
    quint16 clusterId;
    quint8  security;
    quint8  transactionId;
    quint16 dstAddress;
};

#pragma pack(pop)

enum class ZStackVersion
{
    ZStack3x0,
    ZStack30x,
    ZStack12x
};

class ZStack : public Adapter
{
    Q_OBJECT

public:

    ZStack(QSettings *config, QObject *parent);

    bool unicastRequest(quint8 id, quint16 networkAddress, quint8 srcEndPointId, quint8 dstEndPointId, quint16 clusterId, const QByteArray &payload) override;
    bool multicastRequest(quint8 id, quint16 groupId, quint8 srcEndPointId, quint8 dstEndPointId, quint16 clusterId, const QByteArray &payload) override;

    bool unicastInterPanRequest(quint8 id, const QByteArray &ieeeAddress, quint16 clusterId, const QByteArray &payload) override;
    bool broadcastInterPanRequest(quint8 id, quint16 clusterId, const QByteArray &payload) override;

    bool setInterPanChannel(quint8 channel) override;
    void resetInterPanChannel(void) override;

private:

    ZStackVersion m_version;

    quint8 m_status;
    bool m_clear;

    quint16 m_command;
    QByteArray m_replyData;

    QMap <quint16, QByteArray> m_nvItems;
    QList <quint16> m_zdoClusters;

    bool extendedRequest(quint8 id, const QByteArray &address, quint8 dstEndpointId, quint16 dstPanId, quint8 srcEndpointId, quint16 clusterId, const QByteArray &payload, bool group = false);
    bool extendedRequest(quint8 id, quint16 address, quint8 dstEndpointId, quint16 dstPanId, quint8 srcEndpointId, quint16 clusterId, const QByteArray &paylaod, bool group = false);

    bool sendRequest(quint16 command, const QByteArray &data = QByteArray());
    void parsePacket(quint16 command, const QByteArray &data);

    bool writeNvItem(quint16 id, const QByteArray &data);
    bool writeConfiguration(quint16 id, const QByteArray &data);
    bool startCoordinator(void);

    void softReset(void) override;
    void parseData(QByteArray &buffer) override;
    bool permitJoin(bool enabled) override;

private slots:

    void handleQueue(void) override;

signals:

    void dataReceived(void);

};

#endif
