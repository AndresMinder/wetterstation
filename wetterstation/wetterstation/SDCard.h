
#ifndef SDCARD_H_
#define SDCARD_H_

extern void getCardInformations();
extern void readFileSDCard(String filename);
extern void writeFileSDCard(double value2save, String filename);
extern void deleteFileSDCard(String filename);

#endif /* SDCARD_H_ */