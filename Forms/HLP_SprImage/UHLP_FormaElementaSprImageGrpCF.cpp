#include "vcl.h"
#pragma hdrstop  
#include "UHLP_FormaElementaSprImageGrpCF.h"   
#include "UHLP_FormaElementaSprImageGrpImpl.h"  
#include "IHLP_FormaElementaSprImageGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_FormaElementaSprImageGrpCF::THLP_FormaElementaSprImageGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_FormaElementaSprImageGrpCF::~THLP_FormaElementaSprImageGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_FormaElementaSprImageGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_FormaElementaSprImageGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_FormaElementaSprImageGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_FormaElementaSprImageGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_FormaElementaSprImageGrpImpl * ob=new THLP_FormaElementaSprImageGrpImpl();  
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
