#include "vcl.h"
#pragma hdrstop  
#include "UHLP_FormaElementaSprInfBlockGrpCF.h"   
#include "UHLP_FormaElementaSprInfBlockGrpImpl.h"  
#include "IHLP_FormaElementaSprInfBlockGrp.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THLP_FormaElementaSprInfBlockGrpCF::THLP_FormaElementaSprInfBlockGrpCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THLP_FormaElementaSprInfBlockGrpCF::~THLP_FormaElementaSprInfBlockGrpCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockGrpCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int THLP_FormaElementaSprInfBlockGrpCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockGrpCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THLP_FormaElementaSprInfBlockGrpCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THLP_FormaElementaSprInfBlockGrpImpl * ob=new THLP_FormaElementaSprInfBlockGrpImpl();  
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
