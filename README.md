# lib_mecanum_wheel

メカナムホイールを動かすためのライブラリ


## 動作

|                     | 前方 - 左 | 前方 - 右 | 後方 - 左 | 後方 - 右 |
| ------------------- | --------- | --------- | --------- | --------- |
| 前進(北へ)          | Forward   | Forward   | Forward   | Forward   |
| 後進(南へ)          | Backward  | Backward  | Backward  | Backward  |
| 左 横行(西へ)       | Backward  | Forward   | Forward   | Backward  |
| 右 横行(東へ)       | Forward   | Backward  | Backward  | Forward   |
| 左前方 斜行(北西へ) | 0         | Forward   | Forward   | 0         |
| 右前方 斜行(北東へ) | Forward   | 0         | 0         | Forward   |
| 左後方 斜行(南西へ) | Backward  | 0         | 0         | Backward  |
| 右後方 斜行(南東へ) | 0         | Backward  | Backward  | 0         |
| 反時計回り          | Backward  | Forward   | Backward  | Forward   |
| 時計回り            | Forward   | Backward  | Forward   | Backward  |


