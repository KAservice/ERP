#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMSprProducerSectionGrpCF.h"   
#include "UREM_DMSprProducerSectionGrpImpl.h"  
#include "IREM_DMSprProducerSectionGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMSprProducerSectionGrpCF::TREM_DMSprProducerSectionGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMSprProducerSectionGrpCF::~TREM_DMSprProducerSectionGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMSprProducerSectionGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMSprProducerSectionGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMSprProducerSectionGrpImpl * ob=new TREM_DMSprProducerSectionGrpImpl();  
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
