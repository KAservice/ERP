#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMSprGrpTypRabotCF.h"   
#include "UREM_DMSprGrpTypRabotImpl.h"  
#include "IREM_DMSprGrpTypRabot.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMSprGrpTypRabotCF::TREM_DMSprGrpTypRabotCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMSprGrpTypRabotCF::~TREM_DMSprGrpTypRabotCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMSprGrpTypRabotCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMSprGrpTypRabotImpl * ob=new TREM_DMSprGrpTypRabotImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
