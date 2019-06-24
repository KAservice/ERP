#include "vcl.h"
#pragma hdrstop  
#include "UHOT_DMDocViezdCF.h"   
#include "UHOT_DMDocViezdImpl.h"  
#include "IHOT_DMDocViezd.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_DMDocViezdCF::THOT_DMDocViezdCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_DMDocViezdCF::~THOT_DMDocViezdCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_DMDocViezdCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_DMDocViezdCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_DMDocViezdCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_DMDocViezdCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_DMDocViezdImpl * ob=new THOT_DMDocViezdImpl();  
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
