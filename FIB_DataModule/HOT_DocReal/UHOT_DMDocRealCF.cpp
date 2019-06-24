#include "vcl.h"
#pragma hdrstop  
#include "UHOT_DMDocRealCF.h"   
#include "UHOT_DMDocRealImpl.h"  
#include "IHOT_DMDocReal.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_DMDocRealCF::THOT_DMDocRealCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_DMDocRealCF::~THOT_DMDocRealCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_DMDocRealCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THOT_DMDocRealCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_DMDocRealCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_DMDocRealCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_DMDocRealImpl * ob=new THOT_DMDocRealImpl();  
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
