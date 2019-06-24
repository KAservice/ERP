#include "vcl.h"
#pragma hdrstop  
#include "UHLP_DMSprInfBlockCF.h"   
#include "UHLP_DMSprInfBlockImpl.h"  
#include "IHLP_DMSprInfBlock.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_DMSprInfBlockCF::THLP_DMSprInfBlockCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_DMSprInfBlockCF::~THLP_DMSprInfBlockCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_DMSprInfBlockCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_DMSprInfBlockCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_DMSprInfBlockCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_DMSprInfBlockCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_DMSprInfBlockImpl * ob=new THLP_DMSprInfBlockImpl();  
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
