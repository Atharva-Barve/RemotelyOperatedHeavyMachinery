# 🏗️ Remotely Operated Heavy Machinery  

A prototype model of a **remotely operated crane** controlled via **LabVIEW SCADA** and a **handheld controller**. The system utilizes a **TCP/IP connection** for communication and includes a **live video feed** from a camera for remote monitoring.  

## 🚀 Features  
✔️ **Dual Control Mode:** Operate via LabVIEW SCADA or a PS4 controller  
✔️ **Real-time Video Feed:** Camera stream displayed on Raspberry Pi  
✔️ **Wireless Communication:** TCP/IP-based control over Wi-Fi  
✔️ **Servo Motor Control:** Precise movement using an ESP32  

🔹 Project has been developed keeping versatility in mind. Use can be extended to other equipments (with some modifications) apart from cranes.
🔹 The VI is also platform independent & doesn't use any hardware specific VI's. Any WiFi capable microcontroller/controller can be used (Code here is acc. to ESP32 but same logic will work for other as well) .

## 🛠️ System Overview  

### **1️⃣ Hardware Components**  
- **ESP32** - Controls crane movement  
- **Raspberry Pi** - Streams live video feed  
- **PS4 Controller** - Wireless handheld control  
- **Camera Module** - Provides real-time video feedback  
- **Servo Motors** - Move the crane  
- **Wi-Fi Router** - Enables remote connectivity  

### **2️⃣ Software & Tools**  
- **LabVIEW** - SCADA control interface  
- **Python (Raspberry Pi)** - Video streaming & networking  
- **Arduino (ESP32)** - Motor control via TCP/IP  
- **LabVIEW TCP/IP VIs** - Communication handling  

## 🔧 How It Works  
1️⃣ **Start the Raspberry Pi camera stream**  
2️⃣ **Connect the PS4 controller to LabVIEW PC via Bluetooth**  
3️⃣ **LabVIEW sends control commands according to knob values via TCP/IP**  
4️⃣ **ESP32 receives and moves crane accordingly** 
5️⃣ **Live feed assists remote operation** 

---

## 💡 Inspiration & Use Cases  
This project aims to improve **safety & efficiency** in **construction & mining** by enabling **remote operation** of heavy machinery, reducing risk for human operators.  The final aim is to enable **Autonomous operation** in **commercial construction & infrastructure development** which only needs **remote monitoring**
