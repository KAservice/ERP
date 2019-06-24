#include "vcl.h"
#pragma hdrstop  
#include "UHLP_DMSprPageElementCF.h"   
#include "UHLP_DMSprPageElementImpl.h"  
#include "IHLP_DMSprPageElement.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_DMSprPageElementCF::THLP_DMSprPageElementCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_DMSprPageElementCF::~THLP_DMSprPageElementCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_DMSprPageElementCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_DMSprPageElementCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_DMSprPageElementCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_DMSprPageElementCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_DMSprPageElementImpl * ob=new THLP_DMSprPageElementImpl();  
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
