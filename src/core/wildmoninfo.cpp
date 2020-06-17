#include "wildmoninfo.h"
#include "montabwidget.h"



WildMonInfo getDefaultMonInfo(EncounterField field, int timesCount) {
    WildMonInfo newInfo;
    newInfo.active = true;
    newInfo.encounterRate = 0;

    while (timesCount--)
    {
        QVector<WildPokemon> timeMons;
        int size = field.encounterRates.size();
        while (size--)
        {
            timeMons.append(WildPokemon());
        }
        newInfo.wildPokemon.append(timeMons);
    }

    return newInfo;
}

WildMonInfo copyMonInfoFromTab(QTableWidget *monTable, EncounterField monField, QVector<QVector<WildPokemon>> mons) {
    WildMonInfo newInfo;
    int monsPerTimePeriod = monField.encounterRates.count();

    bool extraColumn = !monField.groups.isEmpty();
    for (int time = 0; time < mons.count(); time++)
    {
        QVector<WildPokemon> newWildMons;
        for (int row = 0; row < monsPerTimePeriod; row++) {
            int absoluteRow = row + (monsPerTimePeriod * time);
            WildPokemon newWildMon;
            newWildMon.species = monTable->cellWidget(absoluteRow, extraColumn ? 3 : 2)->findChild<QComboBox *>()->currentText();
            newWildMon.minLevel = monTable->cellWidget(absoluteRow, extraColumn ? 4 : 3)->findChild<QSpinBox *>()->value();
            newWildMon.maxLevel = monTable->cellWidget(absoluteRow, extraColumn ? 5 : 4)->findChild<QSpinBox *>()->value();
            newWildMons.append(newWildMon);
        }
        mons[time] = newWildMons;
    }
    newInfo.active = true;
    newInfo.wildPokemon = mons;
    newInfo.encounterRate = monTable->findChild<QSpinBox *>()->value();

    return newInfo;
}
