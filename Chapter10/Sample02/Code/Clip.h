#ifndef _H_CLIP_
#define _H_CLIP_

#include <vector>
#include <string>
#include "TransformTrack.h"
#include "Pose.h"

class Clip {
protected:
	//! 各ジョイントのTransformトラック配列
	std::vector<TransformTrack> mTracks;
	//! クリップ名
	std::string mName;
	//! クリップの開始時間
	float mStartTime;
	//! クリップの終了時間
	float mEndTime;
	//! ループフラグ
	bool mLooping;
protected:
	//! 時間をクリップの範囲内に調整する
	float AdjustTimeToFitRange(float inTime);
public:
	Clip();
	//! インデックスからジョイントIDを取得する
	unsigned int GetIdAtIndex(unsigned int index);
	//! インデックスからジョイントIDを設定する
	void SetIdAtIndex(unsigned int index, unsigned int id);
	//! トラックの数を取得する
	unsigned int Size();
	//! クリップをサンプリングする
	float Sample(Pose& outPose, float inTime);
	//! トラックを取得する
	TransformTrack& operator[](unsigned int index);
	//! クリップの再生時間を再計算する
	void RecalculateDuration();
	//! クリップ名を取得する
	std::string& GetName();
	//! クリップ名を設定する
	void SetName(const std::string& inNewName);
	//! クリップの再生時間を取得する
	float GetDuration();
	//! クリップの開始時間を取得する
	float GetStartTime();
	//! クリップの終了時間を取得する
	float GetEndTime();
	//! ループフラグを取得する
	bool GetLooping();
	//! ループフラグを設定する
	void SetLooping(bool inLooping);
};

#endif 