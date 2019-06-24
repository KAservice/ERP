#include "vcl.h"
#pragma hdrstop  
#include "UkasMSKFRCF.h"
#include "UkasMSKFRImpl.h"
//#include "IFiskReg.h"
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TkasMSKFRCF::TkasMSKFRCF()
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TkasMSKFRCF::~TkasMSKFRCF()
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TkasMSKFRCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TkasMSKFRCF::kanAddRef(void)
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TkasMSKFRCF::kanRelease(void)
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TkasMSKFRCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{  
int result=0;  
		TkasMSKFRImpl * ob=new TkasMSKFRImpl();
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
