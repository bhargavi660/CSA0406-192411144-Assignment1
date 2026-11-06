# TASK 1: Requirements Analysis for Different Computing Environments

## 1. Introduction

A smart hospital uses different computing environments to provide safe and efficient healthcare services. Each environment has different operating system requirements depending on its purpose.

The main requirements considered are:
- **Response Time:** How quickly the system responds.
- **Reliability:** Ability to work continuously without failure.
- **Throughput:** Amount of work completed in a given time.
- **Battery Life:** Ability to operate for a long time with less power.
- **Security:** Protection of patient information from unauthorized access.

## 2. Requirements Ranking

| Computing Environment | 1st Priority | 2nd Priority | 3rd Priority | 4th Priority | 5th Priority |
|---|---|---|---|---|---|
| Patient Monitors | Response Time | Reliability | Security | Throughput | Battery Life |
| Nurses' Tablets | Battery Life | Security | Reliability | Response Time | Throughput |
| Doctors' Workstations | Security | Response Time | Reliability | Throughput | Battery Life |
| Central Database Server | Reliability | Security | Throughput | Response Time | Battery Life |
| MRI Imaging Server | Throughput | Reliability | Response Time | Security | Battery Life |
| Partner Hospital Network | Security | Reliability | Response Time | Throughput | Battery Life |

*Note: Battery life is not a major requirement for fixed servers and workstations. The rankings are based on the importance of each requirement in the hospital environment.*

## 3. Explanation of Requirements

1. **Patient Monitors:** Fast response time is the highest priority because patient alarms must be generated within 10 milliseconds. Reliability is also important for continuous patient monitoring.

2. **Nurses' Tablets:** Battery life is important because nurses use tablets throughout their shifts. Security is necessary to protect patient information.

3. **Doctors' Workstations:** Security is the highest priority because doctors access confidential medical records. Reliability and response time are also important.

4. **Central Database Server:** Reliability is essential because patient records must always be available. Security and throughput are also important.

5. **MRI Imaging Server:** High throughput is required to process large medical images efficiently using multiple processors. Reliability is important for accurate results.

6. **Partner Hospital Network:** Security is essential when sharing patient records between hospitals. Reliability ensures continuous communication.

## 4. Conflicts Between Requirements

Some operating system requirements may conflict with each other.

- **Response Time vs Throughput:** Handling many users simultaneously may increase delays in responding to critical alarms.
- **Battery Life vs Performance:** Higher processing activity can consume more battery power.
- **Security vs Response Time:** Additional security checks may increase
