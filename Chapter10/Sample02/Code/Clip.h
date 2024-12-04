#ifndef _H_CLIP_
#define _H_CLIP_

#include <vector>
#include <string>
#include "TransformTrack.h"
#include "Pose.h"

class Clip {
protected:
	//! 各ジョイントのTransformTrackの配列
	std::vector<TransformTrack> mTracks;
	//! クリップの名前
	std::string mName;
	//! クリップの開始時間
	float mStartTime;
	//! クリップの終了時間
	float mEndTime;
	//! ループするかどうか
	bool mLooping;
protected:
	//! 時間をクリップの範囲内に調整する
	float AdjustTimeToFitRange(float inTime);
public:
	Clip();
	//! インデックスからIDを取得する
	unsigned int GetIdAtIndex(unsigned int index);
	//! インデックスからIDを設定する
	void SetIdAtIndex(unsigned int index, unsigned int id);
	//! トラックの数を取得する
	unsigned int Size();
	//! ポーズを取得する
	float Sample(Pose& outPose, float inTime);
	//! インデックスからTransformTrackを取得する
	TransformTrack& operator[](unsigned int index);
	//! 持続時間を再計算する
	void RecalculateDuration();
	//! クリップの名前を取得する
	std::string& GetName();
	//! クリップの名前を設定する
	void SetName(const std::string& inNewName);
	//! 持続時間を取得する
	float GetDuration();
	//! 開始時間を取得する
	float GetStartTime();
	//! 終了時間を取得する
	float GetEndTime();
	//! ループするかどうかを取得する
	bool GetLooping();
	//! ループするかどうかを設定する
	void SetLooping(bool inLooping);
};

#endif
