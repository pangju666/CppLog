#pragma once
#include "pch.h"

#include <string>

/**
 * 常用算法函数
 *
 * @author nullptr
 * @version 1.1 2020-8-16 增加获取文件相对路径算法和百分比转化函数
 * @version 1.0 2020-7-13
 * @since 1.0 2020-7-13
 */
namespace algorithm {
	/**
	 *	@brief UTF-8编码字符串转换成ascii编码字符串
	 *
	 * @param utf8Str utf8编码字符串
	 * @return 转换后的ascii编码字符串
	 * @since 1.0
	 */
	std::string utf8StrToAsciiStr(const char* utf8Str);
		
	/**
	 *	@brief UTF-8编码字符串转换成unicode编码字符串
	 *
	 * @param utf8Str utf8编码字符串
	 * @return 转换后的unicode编码字符串
	 * @since 1.0
	 */
	std::wstring utf8StrToUnicodeStr(const char* utf8Str);
	
	/**
	 * @brief 获取当前系统日期，并以字符串形式返回
	 *
	 * @return 当前时间的字符串表示
	 * @since 1.0
	 */
	std::string getNowDateStr();

	/**
	 * @brief 获取当前系统时间，并以字符串形式返回
	 * 
	 * @return 当前时间的字符串表示
	 * @since 1.0 
	 */
	std::string getNowTimeStr();

	/**
	 * @brief 解析日期整数和时间整数表示为字符串
	 * 
	 * @param date 日期整数表示(如：20200320—— 表示为 2020-03-20)
	 * @param time 时间整数表示(如：30900000—— 表示为 3:09:00:000)
	 * @return 解析后的时间字符串
	 * @since 1.0
	 */
	std::string parseDateTimeToString(const int& date, const int& time);
	
	/**
	 * @brief 解析日期整数表示为字符串
	 *
	 * @param date 日期整数表示(如：20200320—— 表示为 2020-03-20)
	 * @return 解析后的时间字符串
	 * @since 1.0
	 */
	std::string parseDateToString(const int& date);

	/**
	 * @brief 解析时间整数表示为字符串
	 *
	 * @param time 时间整数表示(如：30900000—— 表示为 3:09:00:000)
	 * @return 解析后的时间字符串
	 * @since 1.0
	 */
	std::string parseTimeToString(const int& time);

	/**
	 * @brief 时间整数减法运算
	 * 
	 * @param time 时间整数表示(如：30900000—— 表示为 3:09:00:000)
	 * @param seconds 需要减去的秒数
	 * @return 计算得到的新时间整数表示
	 * @since 1.0
	 */
	int subTime(int time, int seconds);

	/**
	 * @brief 获取相对文件路径
	 *
	 * @param absolutePath 绝对文件路径
	 * @return 相对文件路径
	 * @since 1.1
	 */
	std::string getRelativePath(const std::string& absolutePath);
	
	/**
	 * @brief 百分比转化
	 *
	 * @param percentage 百分比小数表示，如3%=0.03， 30%=0.3，30.33%=0.333
	 * @return 百分比的小数表示
	 * @since 1.1
	 */
	double percentageConvert(const double& percentage);

	//std::string formatStr(const char* format, ...);
}