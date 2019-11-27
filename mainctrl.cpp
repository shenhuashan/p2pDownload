#include "mainctrl.h"

#include <QEventLoop>

MainPartner *mainctrl::getPartner() const
{
    return partner;
}

MainFriend *mainctrl::getLocal() const
{
    return local;
}

mainctrl::mainctrl()
{
    //    this->status=ClientStatus::UNKNOWN;//初始化本机状态
//    this->local=Client(0,"localhost","127.0.0.1",DEFAULTPORT,DEFAULTFILEPORT);
//    this->waitingClients.append(this->local);
    //TODO:用配置文件初始化端口配置
    this->udpSocketUtil=new UDPSocketUtil(DEFAULTUDPPORT,SERVERIP,SERVERPORT);
    this->tcpSocketUtil = new TCPSocketUtil(DEFAULTPORT, DEFAULTFILEPORT, true, true, "", ".txt", 1000);
    this->msgUtil=new MsgUtil();
    this->mainctrlutil=new mainCtrlUtil();
    this->local=new MainFriend(this->udpSocketUtil,this->tcpSocketUtil,this->mainctrlutil,this->msgUtil);
    this->partner=new MainPartner(this->udpSocketUtil,this->tcpSocketUtil,this->mainctrlutil,this->msgUtil);
}

/*————————————————————信号槽———————————————————*/
void mainctrl::signalsConnect(){
    qDebug()<<"mainCtrl::连接槽函数";

    //TASKEXECUING 接收伙伴机文件
    qDebug()<<"connect::timeForNextSliceForPartner"<<endl;
    QObject::connect(this->tcpSocketUtil,SIGNAL(timeForNextSliceForPartner(qint32,qint32,qint32)),this->local,SLOT(recParnterSlice(qint32,qint32,qint32)));
    //TASKFINISH 本轮Task接收完成
    qDebug()<<"connect::timeForNextTaskForPartner"<<endl;
    QObject::connect(this->tcpSocketUtil,SIGNAL(timeForNextTaskForPartner(qint32,qint32)),this->local,SLOT(taskEndConfig(qint32,qint32)));
    //本地下载
    qDebug()<<"connect::callAssignTaskToLocal"<<endl;
    QObject::connect(this->local,SIGNAL(callAssignTaskToLocal()),this->local,SLOT(assignTaskToLocal()));
    //本地下载完成
    qDebug()<<"connect::callTaskEndAsLocal"<<endl;
    QObject::connect(this->local,SIGNAL(callTaskEndAsLocal()),this->local,SLOT(taskEndAsLocal()));


    //DOWNLOADTASK 伙伴机开始下载
    qDebug()<<"connect::startToDownload"<<endl;
    QObject::connect(this->tcpSocketUtil,SIGNAL(startToDownload(qint32, qint32, qint64, qint32)),this->partner,SLOT(taskStartAsPartner(qint32, qint32, qint64, qint32)));
    //分片下载完成，伙伴机准备发送
    qDebug()<<"connect::callTaskEndAsPartner"<<endl;
    QObject::connect(this->partner,SIGNAL(callTaskEndAsPartner(qint32, qint32, qint32)),this->partner,SLOT(taskEndAsPartner(qint32, qint32, qint32)));
    //THANKYOURHELP Task分片分发调度
    qDebug()<<"connect::timeForNextSliceForFriend"<<endl;
    QObject::connect(this->tcpSocketUtil,SIGNAL(timeForNextSliceForFriend(qint32, qint32, qint32)),this->partner,SLOT(sliceDivideAndSent(qint32, qint32, qint32)));
    //ENDYOURHELP 帮助下载的任务结束
    qDebug()<<"connect::taskHasFinishedForFriend"<<endl;
    QObject::connect(this->tcpSocketUtil,SIGNAL(taskHasFinishedForFriend(qint32, qint32, qint32)),this->partner,SLOT(missionEndAsPartner(qint32, qint32, qint32)));
    //唤起slice调度器,发送slice
    qDebug()<<"connect::callSliceScheduler"<<endl;
    QObject::connect(this->partner,SIGNAL(callSliceScheduler(qint32,qint32,qint32)),this->partner,SLOT(sliceDivideAndSent(qint32,qint32,qint32)));
    qDebug()<<"mainCtrl::连接槽函数完成";
}
