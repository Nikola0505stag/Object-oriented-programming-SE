#include "ConsultantUtils.h"
#include <cstring>

bool ConsultantUtils::isGoodForGaming(const Computer& computer) {
    const char* proc = computer.getProcessor();
    int video = computer.getVideo();
    int hdd = computer.getHardDrive();

    bool isGoodProcessor = strcmp(proc, "i5") == 0 || strcmp(proc, "i7") == 0;
    bool isGoodVideo = video == 3060 || video == 3070 || video == 3080 || video == 3090;
    bool isGoodStorage = hdd >= 512;

    return isGoodProcessor && isGoodVideo && isGoodStorage;
}

bool ConsultantUtils::isGoodForTravel(const Computer& computer) {
    return computer.getWeight() <= 2 && computer.getBatteryLife() > 6;
}
