#include "xlsxutils.h"

XlsxUtils::XlsxUtils(QString filePath)
{
    xlsx = new Document(filePath);
    if (xlsx->load()) {
        success = true;
    }
}

XlsxUtils::~XlsxUtils()
{
    delete xlsx;
}

QVector<int> XlsxUtils::getUsers()
{

    QList<QString> users;
    QList<int> parsedUsers;

    if (!success)
        return parsedUsers;

    // get full cells of current sheet
    int maxRow = -1;
    int maxCol = -1;

    auto sheet = (Worksheet*)xlsx->currentSheet();

    QVector<CellLocation> clList = sheet->getFullCells(&maxRow, &maxCol);
    qDebug() << maxRow << maxCol;

    QVector<QVector<QString>> cellValues;
    for (int row = 0; row < maxRow; row++)
    {
        QVector<QString> tempValue;
        for (int col = 0; col < maxCol; col++)
        {

            tempValue.push_back(QString(""));
        }
        cellValues.push_back(tempValue);
    }

    for ( int ic = 0; ic < clList.size(); ++ic )
    {
        CellLocation cl = clList.at(ic); // cell location

        int row = cl.row - 1;
        int col = cl.col - 1;

        QSharedPointer<Cell> ptrCell = cl.cell; // cell pointer

        // value of cell
        QVariant var = cl.cell.data()->value();
        QString str = var.toString();

        cellValues[row][col] = str;
    }

    for (auto row : cellValues) {
        if (row.at(4).contains("has uploaded a file")) {
            QString info = row.at(DESCRIPTION_FIELD);
            users.append(info.mid(18, 4));
        }
    }

    users.sort();

    for (auto user : users) {
        parsedUsers.append(user.toInt());
    }

    return parsedUsers;
}

bool XlsxUtils::loaded()
{
    return success;
}
