#pragma once
#include "SCompoundWidget.h"
#include "IDetailsView.h"

class CUSTOMDETAIL_API SCustomWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCustomWidget) {}
	SLATE_ATTRIBUTE(class UMyObject* , DataObj)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TSharedPtr<IDetailsView> ConfigPanel;
	TAttribute<class UMyObject*> DataObj;
};