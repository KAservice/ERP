#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaSpiskaSprHardwareCF.h"   
#include "UREM_FormaSpiskaSprHardwareImpl.h"  
#include "IREM_FormaSpiskaSprHardware.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaSpiskaSprHardwareCF::TREM_FormaSpiskaSprHardwareCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaSpiskaSprHardwareCF::~TREM_FormaSpiskaSprHardwareCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaSpiskaSprHardwareCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaSpiskaSprHardwareCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaSpiskaSprHardwareImpl * ob=new TREM_FormaSpiskaSprHardwareImpl();  
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
