#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

namespace constants {

namespace fileOperations {
const QString FILE_NAME_IS_EMPTY{"File name is empty."};
const QString FILE_OPEN_ERROR{"File open error."};
const QString FILE_IS_OPEN{"File is open."};
}

namespace serialTransceiver {
const QString PORT_IS_OPEN{"Port is open."};
const QString PORT_IS_NOT_OPEN{"Port isn't open."};
const QString QUEUE_IS_EMPTY{"Queue is empty."};
const QString CMD_IS_SEND{"Cmd is send : "};
const QString DATA_IS_RECIVED{"Data is recieved : "};
}

}

#endif // CONSTANTS_H
