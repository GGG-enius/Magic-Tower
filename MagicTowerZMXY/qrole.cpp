 #include "qrole.h"

//定义并初始化一个静态数组用于存储角色TILE信息
//站立，行走1,2, 在战中被打
IDTILE QRole::idTiles[MAX_ROLE_TILE] = {
    144, 145, 146, 147,			//左
    152, 153, 154, 155,			//上
    148, 149, 150, 151,			//右
    138, 141, 142, 143,			//下
};

QRole::QRole(QWidget *parent)
    : QWidget{parent}
{
    m_ptPos = QPoint(5, 9);//Role最开始被载入时的坐标信息
    m_rtWalk.setRect(0, 0, MAP_WIDTH, MAP_HEIGHT);
    m_nTileIndex = 4;//初始化玩家角色最初站立状态
    //初始化角色属性结构体成员
    RoleInfo.nLevel = 1;
    RoleInfo.nHealth = 1000;
    RoleInfo.nAttack = 10;
    RoleInfo.nDefense = 10;
    RoleInfo.nMoney = 0;
    RoleInfo.nExperience = 0;
    RoleInfo.nYellowKey = 1;
    RoleInfo.nBlueKey = 1;
    RoleInfo.nRedKey = 1;

    timer_role = new QTimer(this);
    connect(timer_role, &QTimer::timeout, this, &QRole::onTimer);

    this->setFocusPolicy(Qt::StrongFocus); // 设置窗口可以获取焦点
}

ROLEINFO QRole::getRoleInfo()
{
    return RoleInfo;
}

void QRole::SetRoleInfo(ROLEINFO Info)
{
    RoleInfo = Info;
}

QPoint QRole::getPos()
{
    return m_ptPos;
}

//用于楼梯切换时, 保持出去时与进来时的TILE方向正好相反, bTurn为真表示, 切换, 为假表示不切换
//ptPos表示新的位置。当调用本函数时，这个参数决定角色新的坐标
//idTile表示角色的当前图块索引类型
//bTurn表示是否在楼梯切换时改变角色朝向
void QRole::setPos(QPoint ptPos, IDTILE idTile, bool bTurn)
{
    //获取对应于idTile的图块索引nTileIndex
    int nTileIndex = getTileIndex(idTile);
    //如果bTurn为true，切换方向，计算m_nTileIndex新值如下
    if(bTurn)
    {
        m_nTileIndex = ((nTileIndex / 4) * 4  + 2 + MAX_ROLE_TILE / 2) % MAX_ROLE_TILE;
    }
    else
    {
        m_nTileIndex = ((nTileIndex / 4) * 4  + 2 + MAX_ROLE_TILE / 2) % MAX_ROLE_TILE;
    }
    //更新角色位置
    m_ptPos = ptPos;
}

IDTILE QRole::getRoleTileID()
{
    return idTiles[m_nTileIndex];
}

bool QRole::isRoleTileID(IDTILE idTile)
{
    for(int i=0;i<MAX_ROLE_TILE;i++)
    {
        if(idTiles[i]==idTile)
        {
            return true;
        }
    }
    return false;
}

//当定时器被触发时，调用此函数，更改图块索引，实现行走效果
void QRole::onTimer()
{
    m_nTileIndex--;
    qDebug()<<"定时器被调用";
    qDebug()<<m_nTileIndex;
    //如果图块索引能被 4 整除，则停止定时器，即角色停止行走
    if(m_nTileIndex%4==0)
    {
        timer_role->stop();
    }
}

QPoint QRole::getNextPoint(Qt::Key key)
{
    //初始化一个新的QPoint变量，初值设为当前角色位置m_ptPos
    QPoint r_ptPos = m_ptPos;
    switch(key){
        case Qt::Key_Up:
            r_ptPos.setY(r_ptPos.y()-1);
            m_nTileIndex = 6;
            break;
        case Qt::Key_Down:
            r_ptPos.setY(r_ptPos.y() + 1);
            m_nTileIndex = 14;
            break;
        case Qt::Key_Left:
            r_ptPos.setX(r_ptPos.x() - 1);
            m_nTileIndex = 2;
            break;
        case Qt::Key_Right:
            r_ptPos.setX(r_ptPos.x() + 1);
            m_nTileIndex = 10;
            break;
        default:
            return m_ptPos;//按键不匹配任何方向键
    }
    //触发行走定时器
    timer_role->start(200);
    //检查新坐标r_ptPos是否在m_rtWalk区域内
    if(m_rtWalk.contains(r_ptPos))
    {
        return r_ptPos;
    }
    else
    {
        return m_ptPos;//超范围
    }
}

void QRole::moveTo(QPoint ptPos)
{
    m_ptPos = ptPos;
}


//获取角色图块ID在idTiles数组中的索引
//如果存在返回索引 如果不存在返回默认值4
int QRole::getTileIndex(IDTILE idTile)
{
    for(int i=0;i<MAX_ROLE_TILE;i++)
    {
        if(idTiles[i]==idTile)
        {
            return i;
        }
    }
    return 4;
}
