#include "vcl.h"
#pragma hdrstop  
#include "UHLP_FormaElementaSprNaborInfBlockCF.h"   
#include "UHLP_FormaElementaSprNaborInfBlockImpl.h"  
#include "IHLP_FormaElementaSprNaborInfBlock.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_FormaElementaSprNaborInfBlockCF::THLP_FormaElementaSprNaborInfBlockCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_FormaElementaSprNaborInfBlockCF::~THLP_FormaElementaSprNaborInfBlockCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_FormaElementaSprNaborInfBlockCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_FormaElementaSprNaborInfBlockCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_FormaElementaSprNaborInfBlockImpl * ob=new THLP_FormaElementaSprNaborInfBlockImpl();  
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
