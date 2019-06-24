#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMSprProducerRabotaGrpCF.h"   
#include "UREM_DMSprProducerRabotaGrpImpl.h"  
#include "IREM_DMSprProducerRabotaGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMSprProducerRabotaGrpCF::TREM_DMSprProducerRabotaGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMSprProducerRabotaGrpCF::~TREM_DMSprProducerRabotaGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMSprProducerRabotaGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMSprProducerRabotaGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMSprProducerRabotaGrpImpl * ob=new TREM_DMSprProducerRabotaGrpImpl();  
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
