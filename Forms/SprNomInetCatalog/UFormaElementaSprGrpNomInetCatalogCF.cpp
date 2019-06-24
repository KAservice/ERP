#include "vcl.h"
#pragma hdrstop  
#include "UFormaElementaSprGrpNomInetCatalogCF.h"   
#include "UFormaElementaSprGrpNomInetCatalogImpl.h"  
#include "IFormaElementaSprGrpNomInetCatalog.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TFormaElementaSprGrpNomInetCatalogCF::TFormaElementaSprGrpNomInetCatalogCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TFormaElementaSprGrpNomInetCatalogCF::~TFormaElementaSprGrpNomInetCatalogCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TFormaElementaSprGrpNomInetCatalogCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TFormaElementaSprGrpNomInetCatalogCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TFormaElementaSprGrpNomInetCatalogCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TFormaElementaSprGrpNomInetCatalogCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TFormaElementaSprGrpNomInetCatalogImpl * ob=new TFormaElementaSprGrpNomInetCatalogImpl();  
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
