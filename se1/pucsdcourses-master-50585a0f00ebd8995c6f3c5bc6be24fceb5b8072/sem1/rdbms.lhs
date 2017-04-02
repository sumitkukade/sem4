>import qualified Data.Map.Strict as Map
>import Data.Map (Map)

>data SQuery = Select TableName [ColumnDef] Predicate
>           | Nselect TableName [ColumnDef] [Column] SQuery Predicate -- to handle nested select
>            deriving (Eq, Show)
>data Query = QSelect SQuery
>           | Insert TableName [ColumnDef] [Column]
>           | Update TableName [ColumnDef] [Column] Predicate 
>           | CreateTable TableDef 
>            deriving (Eq, Show)
> -- in our iprdbms we will not provide any Qtrigger, okay?
>data TableDef = TableDef TableName [ColumnDef] PrimaryKey [ForeignKey] [(ColumnDef,ColConstraint)] deriving (Eq, Show)
>data ColumnDef = ColumnDef String deriving (Eq, Show)
>data TableName = TableName String deriving (Eq, Show)
>data PrimaryKey = PrimaryKey [ColumnDef] deriving (Eq, Show)
>data ForeignKey = ForeignKey [(TableName, ColumnDef, ColumnDef)] deriving (Eq, Show)
>data ColConstraint = Unique | Notnull deriving (Eq, Show)
>data NPredicate = SPredicate Predicate | NPredicate 
>data Predicate = Pand Predicate Predicate | Por Predicate Predicate | Pnot Predicate | Ppar Predicate | Plike ColumnDef Column | Pbegin ColumnDef Column | Pend ColumnDef Column  | Pmid ColumnDef Column | Pexact ColumnDef Column deriving (Eq, Show) -- our iprdbms will provide conditions for simple string matching only; no complicated string matching with regular expressions, so our Plike will be actually just Pmid for the time being

and now our grand storage engine

Now we will define our internal data structures to hold the relations
note that our superfast, superefficient and super out-of-the-world rdbms (hereafter referred to as iprdbms will process all data only in primary memory
but it will allow the user to load data from a file and to save data to a file
I will give you the code that will do this IO
You have to implement only the query part.

>data Database = Database DBname [TableDef] [Table] deriving (Eq, Show) 
>data DBname = DBname String deriving (Eq, Show) 
>data Table = Table TableName [ColumnDef] (Map [Column] [Column]) deriving (Eq, Show) -- using lists for rows is very inefficient and so we will use some other more efficient structure like Data.Map 

>data Column = Column String | ColumnNull deriving (Eq, Show)

and finally our grand query engine

>queryEngine :: Database -> Query -> Database 
>queryEngine db (CreateTable tbldefs) = undefined
>queryEngine db (Select stbname coldefs predicate) = undefined
>queryEngine db (Insert stbname coldefs newrow) = undefined
>queryEngine db (Update stbname coldefs colvals predicate) = undefined

-------- the IO part

the format of the persisted database on file system

as discussed in the class, the entire db will be stored in a directory, say, dbdir, by itself
the dbdir will contain a file named "schema" which will contain all information about other files storing tables/relations

the format of the schema file will be as under -
dbname = string
tbldefs = [TableDef]

the files containing the tables in the db will be named as TableName in TableDefs

each file containing the table data will be of the following format
 - csv file
   we will further restrict the users to store only alpha-numeric values and some symbols excluding the delimiter (#) and new-lines in the tables


>store :: Database -> FilePath -> IO ()
>store = undefined
>load :: FilePath -> IO Database 
>load fname = do
> d <- readFile fname
