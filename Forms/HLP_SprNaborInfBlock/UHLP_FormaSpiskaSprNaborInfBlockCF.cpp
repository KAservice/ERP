#include "vcl.h"
#pragma hdrstop  
#include "UHLP_FormaSpiskaSprNaborInfBlockCF.h"   
#include "UHLP_FormaSpiskaSprNaborInfBlockImpl.h"  
#include "IHLP_FormaSpiskaSprNaborInfBlock.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_FormaSpiskaSprNaborInfBlockCF::THLP_FormaSpiskaSprNaborInfBlockCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_FormaSpiskaSprNaborInfBlockCF::~THLP_FormaSpiskaSprNaborInfBlockCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_FormaSpiskaSprNaborInfBlockCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_FormaSpiskaSprNaborInfBlockCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_FormaSpiskaSprNaborInfBlockImpl * ob=new THLP_FormaSpiskaSprNaborInfBlockImpl();  
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
