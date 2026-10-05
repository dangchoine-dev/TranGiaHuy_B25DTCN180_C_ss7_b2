#include <stdio.h>

struct SmartDevice {
    int deviceID;
    char deviceName[50];
    int status;
    float ratedPowerKW;
};

struct EnergySensor {
    float voltageVolts;
    float currentAmperes;
    int unoccupancyMinutes;
};

int main() {
    struct SmartDevice device;
    struct EnergySensor sensor;

    float operatingHours;
    float kwh;
    float money = 0;

    printf("Nhap ma thiet bi: ");
    scanf("%d", &device.deviceID);

    printf("Nhap ten thiet bi: ");
    scanf(" %[^\n]", device.deviceName);

    printf("Nhap trang thai (1-Bat, 0-Tat): ");
    scanf("%d", &device.status);

    printf("Nhap cong suat dinh muc (kW): ");
    scanf("%f", &device.ratedPowerKW);

    printf("Nhap dien ap (V): ");
    scanf("%f", &sensor.voltageVolts);

    printf("Nhap dong dien (A): ");
    scanf("%f", &sensor.currentAmperes);

    printf("Nhap thoi gian vang nguoi (phut): ");
    scanf("%d", &sensor.unoccupancyMinutes);

    printf("Nhap so gio van hanh: ");
    scanf("%f", &operatingHours);

    if (sensor.voltageVolts < 0 ||
        sensor.currentAmperes < 0 ||
        sensor.unoccupancyMinutes < 0) {
        printf("Loi: Du lieu cam bien khong hop le!\n");
        return 0;
    }

    if (operatingHours <= 0 || operatingHours > 744) {
        printf("Loi: So gio van hanh khong hop le!\n");
        return 0;
    }

    if (sensor.currentAmperes > 30.0) {
        device.status = 0;
        printf("CANH BAO: Qua tai dong dien! Da ngat thiet bi.\n");
    }

    if (device.status == 1 && sensor.unoccupancyMinutes >= 15) {
        device.status = 0;
        printf("CANH BAO: Phong vang nguoi! Da tat thiet bi.\n");
    }

    kwh = device.ratedPowerKW * operatingHours;

    if (kwh <= 50) {
        money = kwh * 1806;
    } else if (kwh <= 100) {
        money = 50 * 1806 + (kwh - 50) * 1866;
    } else if (kwh <= 200) {
        money = 50 * 1806 + 50 * 1866 + (kwh - 100) * 2167;
    } else {
        money = 50 * 1806 + 50 * 1866 + 100 * 2167 + (kwh - 200) * 2729;
    }

    printf("\n--- KET QUA ---\n");
    printf("Thiet bi: %s\n", device.deviceName);
    printf("Trang thai: %d\n", device.status);
    printf("Dien nang: %.2f kWh\n", kwh);
    printf("Tien dien: %.0f VND\n", money);

    return 0;
}
//Input:
//* SmartDevice: deviceID, deviceName, status, ratedPowerKW.
//* EnergySensor: voltageVolts, currentAmperes, unoccupancyMinutes.
//* operatingHours.
//Output:
//* Tr?ng thái thi?t b?.
//* C?nh báo quá t?i/v?ng ngu?i.
//* T?ng kWh và ti?n di?n.
//Các bu?c:
//1. Nh?p d? li?u.
//2. Ki?m tra d? li?u c?m bi?n và operatingHours.
//3. Ki?m tra quá t?i > 30A ? t?t thi?t b?.
//4. Ki?m tra v?ng ngu?i >= 15 phút ? t?t thi?t b?.
//5. Tính kWh và ti?n di?n theo b?c thang.
//6. Xu?t k?t qu?.

