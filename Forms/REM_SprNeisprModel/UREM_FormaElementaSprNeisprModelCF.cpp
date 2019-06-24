#include "vcl.h"
#pragma hdrstop  
#include "UREM_FormaElementaSprNeisprModelCF.h"   
#include "UREM_FormaElementaSprNeisprModelImpl.h"  
#include "IREM_FormaElementaSprNeisprModel.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_FormaElementaSprNeisprModelCF::TREM_FormaElementaSprNeisprModelCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_FormaElementaSprNeisprModelCF::~TREM_FormaElementaSprNeisprModelCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_FormaElementaSprNeisprModelCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_FormaElementaSprNeisprModelCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_FormaElementaSprNeisprModelCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_FormaElementaSprNeisprModelCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_FormaElementaSprNeisprModelImpl * ob=new TREM_FormaElementaSprNeisprModelImpl();  
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
