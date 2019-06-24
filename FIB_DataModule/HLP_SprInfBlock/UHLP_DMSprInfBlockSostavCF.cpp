#include "vcl.h"
#pragma hdrstop  
#include "UHLP_DMSprInfBlockSostavCF.h"   
#include "UHLP_DMSprInfBlockSostavImpl.h"  
#include "IHLP_DMSprInfBlockSostav.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_DMSprInfBlockSostavCF::THLP_DMSprInfBlockSostavCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_DMSprInfBlockSostavCF::~THLP_DMSprInfBlockSostavCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_DMSprInfBlockSostavCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_DMSprInfBlockSostavCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_DMSprInfBlockSostavImpl * ob=new THLP_DMSprInfBlockSostavImpl();  
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
