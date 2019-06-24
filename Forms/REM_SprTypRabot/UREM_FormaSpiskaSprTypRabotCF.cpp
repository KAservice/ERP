#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaSpiskaSprTypRabotCF.h"   
#include "UREM_FormaSpiskaSprTypRabotImpl.h"  
#include "IREM_FormaSpiskaSprTypRabot.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaSpiskaSprTypRabotCF::TREM_FormaSpiskaSprTypRabotCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaSpiskaSprTypRabotCF::~TREM_FormaSpiskaSprTypRabotCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaSpiskaSprTypRabotCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaSpiskaSprTypRabotCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaSpiskaSprTypRabotCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaSpiskaSprTypRabotCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaSpiskaSprTypRabotImpl * ob=new TREM_FormaSpiskaSprTypRabotImpl();  
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
