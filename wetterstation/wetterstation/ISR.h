
#ifndef ISR_H_
#define ISR_H_

extern void beginAnemometer(uint8_t digitalPinNumber);
extern void beginOmbrometer(uint8_t digitalPinNumber);
extern void countEdgesAnemometer();
extern void countEdgesOmbrometer();
extern uint32_t getNumberOfEdgesAnemometer();
extern uint32_t getNumberOfEdgesOmbrometer();

#endif /* ISR_H_ */