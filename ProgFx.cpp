#include "ProgFx.h"

void CProgFx::ID_Uppercase()
{	transform (FxId.begin (), FxId.end (), FxId.begin (), toupper);	
}