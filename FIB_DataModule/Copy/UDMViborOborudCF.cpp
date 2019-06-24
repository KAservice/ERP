#include <vcl.h>
#pragma hdrstop
#include "UDMViborOborudCF.h"   
#include "UDMViborOborudImpl.h"  
#include "IDMViborOborud.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMViborOborudCF::TDMViborOborudCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMViborOborudCF::~TDMViborOborudCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMViborOborudCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TDMViborOborudCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMViborOborudCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMViborOborudCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMViborOborudImpl * ob=new TDMViborOborudImpl();  
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
